//Cracked by Roath
// xianliao.c 
// modifiedy by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
	set("short", "�跿");
	set("long", @LONG
�跿�Թű���̸��˵�أ�����С����Ϣ�ĵط����������Ƕ�һȺ��
��һ������ġ�������ĭ��ɣ������컨��׹������ָ�ֻ��ţ�����
�����ࡣ����ͭ���Ĳ販ʿ������ߺ�������ش���
LONG );

	set("exits", ([
		"west" : __DIR__"yongdao5",
//		"east" : __DIR__"eproom",
	]));
	set("cost", 0);

	set("objects", ([ 
	    __DIR__ + "npc/xianren" : 1,
      ]));

	setup();
}
