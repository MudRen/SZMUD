// Code of ShenZhou
// Room: pubu.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "�����ٲ�");
	set("long", @LONG
����һ��ʯ�ڣ���ǰ��Ȼ����һ����к���µ��ٲ���������ص�ˮ�ӱ�
��ȱ�����������󣬼�������������ŷ�֮�䣬�����˴�����Ȼ��������
���ϵ�ˮֱк������һ��������������������������ˮ����������ȵף�
�����ɸߵİ��ˣ�ǡ������ѩ�����ӹ�����һ�㡣����ˮ���ļ��Ҵ˵س�
ů����˲��������
LONG	);
	set("exits", ([ 
              "southwest" : __DIR__"banlp",
              "northup" : __DIR__"tieby",
        ]));
	
        set("fjing", 1);
        set("outdoors", "changbai");
        set("cost", 3);

        set("count", random(3)+1);

	setup();
}
