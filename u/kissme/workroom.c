inherit ROOM;

void create()
{
    set("short","������");
        set("long",@LONG
-------------------------------------------------
���� ���� ���� ���� ���� ���� ���� ���� ����
 ���� ���� ���� ���� ���� ���� ���� ���� ����
  ���� ���� ���� ���� ���� ���� ���� ���� ����
 ���� ���� ���� ���� ���� ���� ���� ���� ����
���� ���� ���� ���� ���� ���� ���� ���� ����
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
        return notify_fail("�㲻�ܵ��Ǳ�ȥ!\n");

    return ::valid_leave(me,dir);
}
