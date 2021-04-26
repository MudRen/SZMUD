// Code of ShenZhou
// Room: /d/newdali/wanrenzhong.c

inherit ROOM;

void create()
{
	set("short", "����ڣ");
	set("long", @LONG
�����챦��䣬���γ�����گ���״�ɥʦ���򣬵ڶ���ɥʦʮ����������
�Ҳ���ˡ�ս�󣬸��߷������ռ��ƾ�������ʿ�ź�����������֮������Ϊ����
���챦սʿڣ���������˳�֮Ϊ������ڣ����
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"chongs",
  "southwest" : __DIR__"southgate",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
