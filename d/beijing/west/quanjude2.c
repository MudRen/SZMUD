//Cracked by Roath
// Room: /d/beijing/west/quanjude2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ȫ�۵¿�Ѽ���¥������������Ŀ��˶��Ǵ�ٹ��˻���
��Ǯ���еİ��칫�Ӹ��������Ҳ��¥��һƬ������һ����������
���ǳ������������Ҳһ��Ц�ݣ������ܵ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"quanjude",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
