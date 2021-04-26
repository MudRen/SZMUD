// Code of ShenZhou
// Room: /d/dali/cangshan.c

inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
��ɽ֮��ʢ����ʯ�����ƴ���ʯ���������ʯ����ʯ����ʯ��ʯ��ϸ�壬ɫ
�ʷḻ���вʻ���ˮī�����ҡ�ѩ�׵�Ʒ�֡�ˮī��Ϊϡ�У��ʻ������ص㣬��
������������ͣ�������ɽ������������֮�Σ���̬��ǧ��������ɣ�Ϊ��������
����ʯ�Ǿ����Ľ������ϣ�������ǽ�̵أ����������������ˮ������������ѩ
��ʯ������԰��񣬾�Ө�ɰ��������֬���ǵ�̡��滭�ĺò��ϡ�ʯ���Բ���
������������������·����ֻ�ʯ�Գƴ���ʯ��������Ҳ���ʯ���������¡�
LONG);
	set("exits", ([
		"southwest" : __DIR__"xiaguan.c",
		"north" : __DIR__"shilin1.c",
		"east" : __DIR__"hongshengt.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
