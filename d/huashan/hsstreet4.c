// Code of ShenZhou
// hsstreet3
// qfy Oct 15, 97

inherit ROOM;

void create()
{
	set("short", "������·");
	set("long", @LONG
�����ǻ�ɽ���µ���·���ο��ǻ����������Σ����²�����ǰȥ��
ɽ��ˮ����������֮һ�Ļ�ɽ�ɱ��ڻ�ɽ��Ů��֮�ϣ��ʴ˾������Կ���
����彣�Ļ�ɽ���ӡ�ż��Ҳ����ɫ�Ҵҵ�����������ʿ������ɷ��
��ͷɥ����
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"hsstreet3",
		"east" : __DIR__"path1",
	]));
	
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("cost", 2);
	setup();
	replace_program(ROOM);
}