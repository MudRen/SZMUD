// huayuan.c   ������/��԰
// snowlf by 2001.12.19

#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIG"��԰"NOR);
        set("long","
    ����԰�У�ͥԺ���ģ����ֻ������ǲ��١��ٻ����ţ�ɽʯ��׾����
�����壬���ɴ��񣬾���ɷ�����ˡ��峺��Ϫ����������һ��Сͤ�ӡ�
    ���B�餤�A�x�|�M�աA���ت�c�ƬO���֡C�ʪᪧ��A�s�ۥj��A��
�h���M�A�a�P�A�ˡA���P�٬O�y�H�C�M�����ˬy���q�ߵۤ@�y�p�F�l�C

    "+HIM+"���������棬�����е����������Ŀ�������
"NOR);

        set("valid_startroom",1);
        
        set("exits", ([
		"enter" : __DIR__"qingxinting",  
		"south" : __DIR__"study",
		"east" : __DIR__"jiuqu3",
		"west" : __DIR__"jiuqu4",
		"southwest" : __DIR__"jiuqu5",
		"northwest" : __DIR__"jiuqu2",		
        ]));

        set("item_desc", ([
                        "lotus flower": "������Ҷ����̣�ӳ�պɻ������죡\n",
			"������ɫ": "������Ҷ����̣�ӳ�պɻ������죡\n",
			"south": "
��ի - /u/xrz/snowlf/study

    ��ի���������һ��������   
    
	     		�ƻ�ҹ������ζ  
	     		ī����տ������
    
    ���Ŷ��룬���������ŵķ�����һ��"+HIW+"����"+NOR+"(desk)���Ա߿�ǽ��������
���Ϸ������飬���Ϸ���һ��"+HIR+"ɺ��"+NOR+"�辰���ݶ���Ƕһ��˶���"+HIW+"ҹ����"+NOR+"(yemingzhu)��

    �������Եĳ����� west �� out�C"
                        ]));     
        set("valid_startroom",1);
        set("no_clean_up",0);
        set("no_fight",0);
        set("no_steal",0);
        setup();

}
