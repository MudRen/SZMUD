// kuayuan.c ����������Ժ
// snowlf by 2001.09.17
// snowlf change of 2001.9.30 (add board)  
#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIG"��Ժ"NOR);
        set("long","�������������������ŵ���Ժ��ӭ��һ���������磬��סԺ�ڵľ����ʱ
�����ֺͻ�Ц����Ժ�д���������������ֻ�ɰ��İ�ɫ���ӡ��������Ĺ������
����Ժ�ڡ�
    
"NOR);

        set("valid_startroom",1);
        
        set("exits", ([
         	"left" : __DIR__"neiyuan",
		"right" : __DIR__"neiyuan",
		"east" : "/u/snowlf/workroom",

		
        ]));


        set("valid_startroom",1);
        set("no_clean_up",0);
        set("no_fight",1);
        set("no_steal",1);
        set("objects",([ 
                __DIR__"npc/gezi":2,                
       
	])); 
        setup();

}
