// Code of ShenZhou
// Room: /d/newdali/tusi2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Լ�����һЩ������������Ȳ֣����������������ж��׶������
��Χǽ�����彨���ǹ�ģ�������������������ϵ�����Ъɽ������ʽ��
��������ʮ�ߣ�����ʮ���壬����ʮ�ߡ���¥�������ټ���Сͷ�����ص㣬
Ҳ�������ҡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"tusi3",
  "north" : __DIR__"tusi4",
  "out" : __DIR__"tusi1",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
