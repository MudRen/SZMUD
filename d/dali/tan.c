// Code of ShenZhou
// Room: /d/newdali/tan.c

inherit ROOM;

void create()
{
	set("short", "����̶");
	set("long", @LONG
����̶��Ȫ�羵����ǰ����أ�����һ�������һȪˮ�壬��Լ��Ķ��
ˮ����ʮ���ɣ������ɫ��һȪˮ�ǣ���ԼһĶ��ˮɫ΢�ơ���Ȫ������
������ˮɫ���죬һ��һ�ʣ��Ա�������������ҵ�̫��ͼ�����˶����
�ء����ؽ�Χ������ʯ������ˮ���������û������Χ�����ͣ���Ȼ�Եá�
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"ling",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
