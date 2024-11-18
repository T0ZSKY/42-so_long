#!/bin/bash

WIDTH=$((RANDOM % 15 + 10))
HEIGHT=$((RANDOM % 10 + 7))

generate_map() {
    local map=""
    local x y
    local start_placed=0
    local exit_placed=0
    local item_placed=0
    local num_items

    num_items=$((RANDOM % (WIDTH * HEIGHT / 4) + 1))

    for ((y=0; y<HEIGHT; y++)); do
        line=""
        for ((x=0; x<WIDTH; x++)); do
            if ((x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1)); then
                line+="1"
            else
                line+="0"
            fi
        done
        map+="$line\n"
    done

    while [[ $start_placed -eq 0 ]]; do
        x=$((RANDOM % (WIDTH - 2) + 1))
        y=$((RANDOM % (HEIGHT - 2) + 1))
        if [[ ${map:$((y * (WIDTH + 1) + x)):1} == "0" ]]; then
            map="${map:0:$((y * (WIDTH + 1) + x))}P${map:$((y * (WIDTH + 1) + x + 1))}"
            start_placed=1
        fi
    done

    while [[ $exit_placed -eq 0 ]]; do
        x=$((RANDOM % (WIDTH - 2) + 1))
        y=$((RANDOM % (HEIGHT - 2) + 1))
        if [[ ${map:$((y * (WIDTH + 1) + x)):1} == "0" ]]; then
            map="${map:0:$((y * (WIDTH + 1) + x))}E${map:$((y * (WIDTH + 1) + x + 1))}"
            exit_placed=1
        fi
    done

    for ((i=0; i<num_items; i++)); do
        while [[ $item_placed -eq 0 ]]; do
            x=$((RANDOM % (WIDTH - 2) + 1))
            y=$((RANDOM % (HEIGHT - 2) + 1))
            if [[ ${map:$((y * (WIDTH + 1) + x)):1} == "0" ]]; then
                map="${map:0:$((y * (WIDTH + 1) + x))}C${map:$((y * (WIDTH + 1) + x + 1))}"
                item_placed=1
            fi
        done
        item_placed=0
    done

    echo -e "$map"
}

generate_map
