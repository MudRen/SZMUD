// Code of ShenZhou
// Room: /d/hangzhou/hl1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
һ��ɽ�ţ����򽻴䣬���ж��졣ʯ�ڶ�����̦�۳��̣�������
�أ����ܽᡣ����ʯ���ϵ�̵Ļ���ͷ��Ȫˮ��������ע��ء�����
֮����һС�壬���⣺���������顱��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"beishan1",
]));
	set("objects", ([
                "/d/xingxiu/npc/snake" : 1,
        ]));

	set("cost", 3);
	setup();
	replace_program(ROOM);
}
