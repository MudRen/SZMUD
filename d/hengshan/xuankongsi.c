//Cracked by Roath
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������������");
        set("long", 
"Ϊ������ɽ��һ��ۣ����������������ɸ������������
�����嶥����������¥�������ƶˡ������ɸ�Ը����㣬
������ʮ�ɣ������ʮ������¥�Է���������\n");
        
set("exits", ([
                "northup"  : __DIR__"shenshege",
                "southup"   : __DIR__"lingguige",
                "westdown" : __DIR__"ciyaokou",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hengshan");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

