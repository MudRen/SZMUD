//Cracked by Roath
// Room: /d/beijing/east/yonghegong.c

inherit ROOM;

void create()
{
	set("short", "Ӻ�͹�");
	set("long", @LONG
Ӻ�͹��Ǳ���������������������͢����ȫ�������
��������ġ�Ӻ�͹������������ɡ��ظ��彨��������һ�壬
���в���������ֵ���ߵĹ���Ʒ������ÿ�����³��ˣ�Ӻ�͹�
��Ҫ���ݡ����������ӭ�顣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  	"west" : __DIR__"guozijianjie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
