//Cracked by Roath
// Room: /d/beijing/west/xitianmen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������̳�������ţ���̳����������̳ǽ��̳ǽ�Ϸ���
Բ����������Բ�ط������ǻʵ�����ȷ�ǵĳ�����������
�����ϣ����������ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"baihuayuan",
  "west" : __DIR__"shizilukou",
  "east" : __DIR__"shibanlu1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
