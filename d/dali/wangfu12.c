// Code of ShenZhou
// Room: /d/dali/wangfu12.c

inherit ROOM;

void create()
{
	set("short", "˯��");
	set("long", @LONG
���˷��ݣ�ѩ��һ�㣬һɫ������ȫ�ޡ�����ֻ��һ������
ƿ��ƿ�й�����֦�գ��������飬���ơ��������ѣ�����ֻ����
��ɴ��ᣣ�����Ҳʮ�����ء�������������齣���϶���������
������ÿһ�ǰ���ŵ��Ἰ��Ҳ�к���ʽ�ģ�Ҳ��÷��ʽ�ģ�Ҳ
�к�Ҷʽ�ģ�Ҳ�п���ʽ�ģ�Ҳ�з��ģ�Ҳ��Բ�ģ���ʽ��һ��
һ����ͷ����һ��¯ƿ��һ���ܺС�
LONG
	);
	set("cost", 1);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"wangfu11",
  "east" : __DIR__"wangfu13",
]));
	set("no_clean_up", 0);
set("wangfu", 1);

	setup();
	replace_program(ROOM);
}
