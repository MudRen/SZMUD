inherit ROOM;

void create()
{
    set("short","工作室");
        set("long",@LONG
-------------------------------------------------
工作 工作 工作 工作 工作 工作 工作 工作 工作
 工作 工作 工作 工作 工作 工作 工作 工作 工作
  工作 工作 工作 工作 工作 工作 工作 工作 工作
 工作 工作 工作 工作 工作 工作 工作 工作 工作
工作 工作 工作 工作 工作 工作 工作 工作 工作
-------------------------------------------------
LONG
);
    set("exits",([
        "wz":"/d/wizard/wizard_room",
        "hangzhou":"/d/hangzhou/road42",
        "gumu":"/d/gumu/dating",
        "yz":"/d/city/kedian",
          "quanzhou":"/d/quanzhou/yaopu",
        "xixia":"/d/xixia/beidajie",
        "beijing":"/d/beijing/kedian",
]));
    set("no_sleep_room",1);
      set("no_fight",1);
setup();
}

int valid_leave(object me,string dir)
{
      if(!wizardp(me) && dir == "wz")
        return notify_fail("你不能到那边去!\n");

    return ::valid_leave(me,dir);
}
