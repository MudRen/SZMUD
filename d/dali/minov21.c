// Code of ShenZhou
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ǿ�ڲ��Ĵ�����ôЩ����ľ۾�����ôЩ�����ǰ���
��һ֧���˴�Ҳ��ɽ���С��ƽԭ����������һƬ��ˮ������������
��ط���΢ƫԶЩ�������൱���ٵİ����������ڸ��������Ϸ��е�
·ͨ����������
LONG
        );

	set("exits", ([
		"westup" : __DIR__"minov18",
		"northeast" : __DIR__"minov22",
		"southup" : __DIR__"minov25",
		"southwest" : __DIR__"minov26",
		]));

	set("objects", ([
		"/d/dali/npc/byshang.c" : 1,
		]));

	set("outdoors","dali");
       set("fjing", 1);
	set("cost", 2);
	setup();
}
