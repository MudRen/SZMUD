// Code of ShenZhou
// Room: /d/mingjiao/yingw.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "ӥ����");
	set("long", @LONG
�˼�������ӥ�����á���������ש������һϯ��̺���������δ���
�ڷţ����ǿ������������б����ܣ��ϰ�ʮ��������������ǽ���ϻ���һ
ֻ��ӥ��˫ü��ͦ����չ˫�ᣬ���ڿ��а��裬�Ե��������ݡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"daguangchang",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
