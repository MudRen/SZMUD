//xiuxishi.c (kunlun)

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "休息室");
        set("long", @LONG
这是间整洁的厢房，因门窗常闭着，光线很昏暗。房里放着几张收拾得
舒舒服服的木床，看着就让人想睡觉。
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);

        set("exits",([
                 "south" : __DIR__"liangong",
                  "southeast" : __DIR__"chufang",
        ]));


        set("cost", 0);
        setup();
        //replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i;


        inv = all_inventory(me);

        if ( dir == "southeast" || dir == "south" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("你不能带着其他玩家离开休息室。\n");
                }
        }

        return ::valid_leave(me, dir);
}
