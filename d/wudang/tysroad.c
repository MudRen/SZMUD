// Code of ShenZhou
// tysroad.c ��԰С·
// by Marz 
// Modified by xQin 04/01

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
��ǰ��Ȼ���ʣ������ɵ�������԰�ߵ�С·�ϡ�·����Ӣ�ͷף�һ����
�����֣�ʢ���ŷۺ���һ�������һƬ���������ߡ������Կ����۷䡸����
�����ڻ�����Ϸ���æ����ͣ�������Գ���ߴզ����������䵱ɽ�ţ�
�ϱ�������ɽ�Ļ���·��
LONG
	);
	set("outdoors", "wudang");

	set("exits", ([
		"north" : __DIR__"tyroad8",
	]));
	
	set("objects", ([
		__DIR__"npc/"+npcs[i] : 1]));
	        
	set("cost", 1);
	setup();
}
