inherit ROOM;

void create()
{
    set("short","工作室");
    set("long","闹中取静的好去处。\n");
    set("exits",([
        "wz":"/d/wizard/wizard_room",
     ]));
    setup();
}
