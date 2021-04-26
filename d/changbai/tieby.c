// Code of ShenZhou
// Room: tieby.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "������");
	set("long", @LONG
�������ٲ������һ��С·���ݳ�鶺Ӷ��ϡ����·��Ϊ�վ���һ����
���ڣ�һ�����������֡��������ˣ�ֻ���泯���ڣ��������ڲ����������
��Σ�ա�
LONG	);

	set("exits", ([ 
              "southdown" : __DIR__"pubu",
              "eastup" : __DIR__"jiglz",
        ]));

        set("objects",([
                __DIR__"npc/sai" : 1,
        ]));
	
        set("outdoors", "changbai");
        set("cost", 4);

        set("count", random(3)+1);

	setup();
}
