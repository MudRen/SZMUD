// Code of ShenZhou
// Room: erld.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "������");
	set("long", @LONG
����������ɽ֮�У��Ĵ����Ǻ��Ļ�ѩ�͸ߴ����ľ��ѩ����ż����
����һЩ�������µĽ�ӡ����ǳ��һ��Զ��ɽ���ﴫ��һ�������޵ĺ�����
�����˴����������޳�û�����ǿ���뿪�ĺá�
LONG	);
	set("exits", ([ 
              "northdown" : __DIR__"jiaxz",
              "southeast" : __DIR__"banlp",
        ]));
	
        set("outdoors", "changbai");
        set("cost", 3);

        set("count", random(3)+1);

	setup();
}
