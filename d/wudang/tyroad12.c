// Code of ShenZhou
// tyroad12.c ��԰С·
// by Marz 

inherit ROOM;

string* npcs = ({
	"little_monkey",
	"monkey",
	"little_monkey",
	"little_bee",
	"bee",
	"little_bee",
});
                                

void create()
{
	int i = random(sizeof(npcs));
	    
	set("short", "��԰С·");
	set("long", @LONG
	��ǰ��Ȼ���ʣ������ɵ�������԰�ߵ�С·�ϡ�·����Ӣ�ͷף������������֣�
ʢ���ŷۺ���һ�������һƬ���������ߡ������Կ��۷䡸���ˡ����ڻ�����Ϸ�
��æ����ͣ�������Գ���ߴզ����
LONG
	);
	set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"tyroad9",
	]));
	
	set("objects", ([
		__DIR__"npc/"+npcs[i] : 1]));
	        
	set("cost", 1);
	setup();
}
