//Cracked by Roath
// Room: /d/beijing/west/xizhidajie2.c

inherit ROOM;

void create()
{
	set("short", "��ֱ�Ŵ��");
	set("long", @LONG
����һ��ʮ�ֿ����Ĵ�֡������������൱���֡��м���С��
�����ؽֽ�����ʲ�ᣬż�м������˻�ͣ����פ���ʼۡ��������
����ȥ���ɿ�����¥�͹�¥�ļⶥ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"guloudajie2",
  "east" : __DIR__"guloudajie2",
  "southwest" : __DIR__"xizhidajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
