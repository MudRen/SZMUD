//Cracked by Roath
// Dong 1/9/98
// modifiedy by aln 5 / 98
// Ssy

inherit __DIR__"no_pk_room";

void create()
{
    	set("short", "ɳ̲");
    	set("long", @LONG
ɳ̲���Ǻܴ󣬰װ׵�ϸɳ�������౴�ǣ����˳����������
��������ʮ�ֺÿ���ɳ̲�ľ�ͷ��һ�´�ʯ�ڡ��м���Ů����̤����
ˣ�š�ż���ɼ����СС�ĺ���������ȥ��
LONG
    	);

    	set("exits", ([
		       "northeast" : __DIR__"jiaoshi3",
		       "west" : __DIR__"shatans2",
		       ]));
    	set("outdoors", "xiakedao");
	set("objects", ([ 
			 __DIR__"npc/haigui" : 1, 
			 ]));

    	setup();
}


