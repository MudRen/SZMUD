// Code of ShenZhou
// Room: /d/murong/hubian
// Date: arthurgu/ 1999.9.1

#include <room.h>
inherit ROOM;

int do_find(string);
int do_wen(string);

void waittime( object ob ) ;

void create()
{
    set("short", "����");
    set("long", @LONG
    ���ߵ�����,ǰ���Ȼһ�������(hu),ˮ��⻬�羵����������
���о�,����������ů����Ĵ��紵������,������ѬѬ����
LONG
    );

    set("exits", ([
        "east" : __DIR__"road1",
    ]));

         set("item_desc", ([
              "hu" :
"    ��������ޱȣ�һ���ޱߡ�ԶԶ��ȥ�����������˺����ź��
΢�紵������Ҷ��ҡ��ɷ�Ƕ��ˡ�ź��֮�䣬��һ����������ˮ·��
��֪��ͨ��δ�����Զ��ˮ·�䣬��һ��С��(zhou)������ҡ����
",
               "zhou" :
"   С����С����������Ҳ�������������ˡ�һ������Ů��(girl)
��ִ˫����������ˮ���������г���С��������������а�����ö��ġ�
",
               "girl" :
"   ֻ������Ůһ˫����������ӳ���̲�������͸��һ�㡣ԼĪ
ʮ��������ͣ������������ᣬ����������������Ҫȥ�����룬��
Ҫ����������(wen)��
",

                            ]));

      
    
    set("outdoors", "murong");
    setup();

}

void init()
{
    add_action("do_find", "find");
    add_action("do_wen", "wen");
}


int do_find(string arg)
{
	object me;
	object *inv;
	int i;
	me=this_player();

	if (arg=="boat" && me->query("family/family_name")=="����Ľ��")
	{
			
		inv=all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			if (userp(inv[i]))
				return notify_fail("�㸺��̫���ˣ�С�ۿ����ز����㡣\n");
		}
		tell_object(me, "��������·���ҵ�һ��С�ۣ��⿪���ӣ�����������\n");
		tell_object(me, "��һ������������κ�ׯ��\n");
		me->move("/d/murong/zhuang1.c");
		return 1;
	}
	return 0;
}


int do_wen(string arg)
{
    object ob ;
    ob = this_player () ;

    message_vision("��������Ů�Ӵ���ȥ�κ�ׯ��· \n",ob);
    message_vision("����Ů��΢΢һЦ�������֪���κ�ׯ������, ����Ǳ�ׯ���ˣ�����������ׯ�ɡ�\n",ob);
    message_vision("\n$NԾ��С�ۣ����ͻ���������\n\n" ,ob );
    ob ->move("/d/murong/dahu") ;
    tell_object(ob, "\nС���ں���ź��֮���ˮ·�ϴ�����ȥ������۶�����...\n\n" ) ;
    call_out("waittime", 50 , ob );
    return 1 ;
}
void waittime( object ob )
{
  tell_object(ob, "\nС�����ڻ�����������ǰ��һ�仪���Ĵ��ݡ�\n\n" ) ;
  ob->move ("/d/murong/qing1") ;
}