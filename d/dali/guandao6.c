// Code of ShenZhou
// Room: /d/dali/guandao6.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����һ��������᫵�ɽ����·��������ԭͨ�����Ĺٵ����˴�
�����ϣ�������ȥ����ɽ·ͨ���ƹ�ɽ�����̶��ɴ����Ѵ��������
ȥ�򱱲�Զ������������--����ɽ��
LONG
	);

	set("cost", 3);

	set("outdoors", "dali");

	set("exits", ([
		"northeast" : "/d/emei/shijie1",
		"southwest" : __DIR__"guandao5",
		]));

	set("no_clean_up", 0);
	setup();
}
