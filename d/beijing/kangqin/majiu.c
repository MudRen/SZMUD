//Cracked by Roath
// Room: /d/beijing/kangqin/majiu.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
��������������ǡ��������ᰮ�������˺ܶྫ��
�ͽ�Ǯ�����˲��ٺ�����������һ��ɲݣ���ǽ������
���������ġ������ϲ۲�Զ���Ǹ����ӣ�����ϴ���Ա�
�п�ɳ�أ��ɹ��������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"neijiu",
  "north" : __DIR__"zhoulang9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
