// outdoor.c zip@hero 2000.1.27 �����ſ�
#include <ansi.h>
#define ID 600
inherit ROOM;
void create()
{       
    string *dir=({"��","��"});
    set("short",HIG"���ݴ��"+chinese_number(ID/100)+"��"+dir[ID%2]+NOR);
    set("long", 
            HIC"    ������ˮ��(mariner)��С����\n"NOR +
            HIC"    СС��"+HIB"����"NOR+HIC"��\n"NOR
            );
    set("exits",([
    "west" : __DIR__"street"+(string)(ID/100),
    ]));
    set("owner","mariner");
    set("coor/x",40+(ID%2)*20);
    set("coor/y",20+(ID/100)*10);
    set("coor/z",0);
    setup();
}
#include "outdoor_func.c"
