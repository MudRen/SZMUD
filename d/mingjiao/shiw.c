// Code of ShenZhou
// Room: /d/mingjiao/shiw.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "ʨ����");
	set("long", @LONG
�˼�������ʨ������а��貢���ݳޣ����ɾ����䣬�����ྲ����
�����б����ܣ��ϰ�ʮ������������ǽ���ϻ���һֻ��ɫ��ʨ��ʨ�ڴ��ţ�
�������ں�У��������ư��硣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"daguangchang",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
