//Cracked by Roath
// Room: /d/beijing/west/xizhidajie.c

inherit ROOM;

void create()
{
	set("short", "��ֱ�Ŵ��");
	set("long", @LONG
����һ��ʮ�ֿ����Ĵ�֡������������൱���֡��м���С��
�����ؽֽ�����ʲ�ᣬż�м������˻�ͣ����פ���ʼۡ���������
С��ͬ������������ֱ�š�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"xizhidajie2",
  "west" : __DIR__"xizhimen",
  "south" : __DIR__"baozhu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
