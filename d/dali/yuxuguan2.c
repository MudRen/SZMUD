// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�������ʮ����죬���й����Ź��ϡ�������������õȰ��ɵ�
����������ƣ������ϰ���Щ��ҡ����з��˼������š��Ա�һ��
С����������Σ�������ɢ����Ϣ����ͽ�ĵط���
LONG
	);

	set("exits", ([
		"south" : __DIR__"yuxuguan1.c",
	]));

	set("objects", ([
		"/kungfu/class/dali/daobaifeng.c" : 1,
	]));

	set("cost", 1);
	setup();
}
