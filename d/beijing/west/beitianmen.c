//Cracked by Roath
// Room: /d/beijing/west/beitianmen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������̳�ı����ţ���̳����������̳ǽ��̳ǽ�Ϸ�
��Բ����������Բ�ط������ǻʵ�����ȷ�ǵĳ���������
�������ϣ����������ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"xiaohutong1",
  "south" : __DIR__"shibanlu4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
