//Cracked by Roath
// ������
// Ssy

inherit __DIR__"no_pk_room";
string* npcs = ({
        "haidao_s",
        "haidao_o",
        "haidao_w",
});

void create()
{
        int i = random(sizeof(npcs));
        int j = random(sizeof(npcs));

    	set("short", "������");
    	set("long", @LONG
�������������ã�����ֻ�м���С����һ����������ϻ�����
�����ˡ�
LONG
    	);

    	set("exits", ([
		       "out" : __DIR__"haidaowo",
		       ]));
        set("objects", ([ 
			 __DIR__"npc/"+npcs[i] : 1,
                         __DIR__"npc/"+npcs[j] : 1,
			 ]));

    	setup();
}


