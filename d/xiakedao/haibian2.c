//Cracked by Roath
// Dong 1/9/98
// modifiedy by aln 5 / 98
// Ssy

inherit __DIR__"no_pk_room";

void create()
{
    	set("short", "����");
    	set("long", @LONG
һ���޼ʵĴ󺣷������⣬���ռ䳱�����ȣ�����ҹ�����¹�
���������˵���һƬ��ٳ��⡣��������һ�Ÿ߸ߵ�Ҭ���������ϻ�
���ż�ֻҬ�ӡ�һ�󺣷紵����Ҭ�������ҡ���ţ�Ҭ�Ӻ����Ҫ��
�����Ƶġ�
LONG
    	);

    	set("exits", ([
		       "north" : __DIR__"haibian1",
		       "south" : __DIR__"haibian3",
		       "east" : __DIR__"xiaolu2",
		       ]));
    	set("outdoors", "xiakedao");
	set("objects", ([ 
			 __DIR__"obj/yezitree" : 1, 
			 __DIR__"npc/emei" : 1,
			 ]));

    	setup();
}


