.name "Terminator"
.comment "Corewar ez"

to_write: sti r1 %:say_alive_1 %1

say_alive_1: live %234

    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write

    lfork %:say_alive_5

    sti r1 %:say_alive_2 %1
say_alive_2: live %234

        st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write

    lfork %:say_alive_5

        sti r1 %:say_alive_3 %1
say_alive_3: live %234

        st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write

    lfork %:say_alive_5

sti r1 %:say_alive_4 %1
say_alive_4: live %234

    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write
    st r16 :to_write

    lfork %:say_alive_5

sti r1 %:say_alive_5 %1
say_alive_5: live %234

ld %0 r3
zjmp %:to_write
