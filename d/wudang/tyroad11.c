// Code of ShenZhou
// tyroad11.c ��԰С·
// by Marz 
// xQin 04/01

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
��ǰ��Ȼ���ʣ������ɵ�������԰�ߵ�С·�ϡ������������֣�����ʢ
���ŷۺ���һ�������һƬ���������ߡ���ʱ���۷䡸���ˡ��طɹ�����ʧ
���ڻ����У���ֻ���������ϻ���׷���ţ�ߴߴ�������������ӡ�
LONG
	);
	set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"tyroad10",
	]));
	
	set("objects", ([
		__DIR__"npc/"+npcs[i] : 1]));
	        
	set("cost", 1);
	setup();
}
