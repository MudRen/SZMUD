// Code of ShenZhou
// Room: /d/dali/wuhua2.c

inherit ROOM;

void create()
{
	set("short", "¥��");
	set("long", @LONG
�����ͨ����¥��ӭ��ի����¥�ݣ�¥�ݸ�����ʮ�༶��������
���ʺ��ëձ��¥������վ��һЩ������ʿ��¥�����ǹ����Ϣ�ĵ�
����
LONG
	);
	set("exits", ([
		"south" : __DIR__"wuhua1.c",
		"up" : __DIR__"wuhua3.c",
		]));
	set("objects", ([
		"kungfu/class/dali/gaoshengtai" : 1,
		"d/dali/npc/weishi4.c" : 3,
        ]));


	set("no_clean_up", 0);
	set("cost", 1);

	setup();
}
