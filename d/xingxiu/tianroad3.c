// Code of ShenZhou
// room: /d/xingxiu/tianroad3.c
// Jay 3/18/96

#include <ansi.h>

inherit F_CLEAN_UP;
inherit ROOM;

void init();
int do_jump(string);

void create()
{
        set("short", "��ɽɽ·");
        set("long", @LONG
��������ɽ��´��ɽ���ɽ�ϴ����������ɪɪ������·����һƬ��ԭ��
����һ���(valley)��ס����ɽ��·��
LONG
        );
        set("exits", ([
            "northup" : __DIR__"xxroad4",
            "eastdown" : __DIR__"gangou2",
]));
        set("item_desc", ([
                "valley" : "������ɶ����֪���ܲ�����(jump)��ȥ��\n"
        ]) );

        set("objects", ([
                "/kungfu/class/xingxiu/azi" : 1
        ]));
        set("resource/grass", 1);
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        set("bing_can", 10);
        set("cost", 3);
        setup();
        //replace_program(ROOM);
}
void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        int i;
        object me, *ob;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        
        if( arg=="valley" ) {
        
        	if( me->query("rided") ){
                          message("vision", me->name()+"�͵�һ�����������µ���һ����˻Խ�������\n",
         		  environment(me), ({me}) );
                          write("���͵�һ�����������µ���һ����˻Խ�������\n");
                          ob = all_inventory(environment(me));
        		  for(i=0; i<sizeof(ob); i++){
        	          	if( ob[i]->query("rider") == me )
        		  	ob[i]->move("/d/xingxiu/tianroad4");
        		  }
          
 	                  me->move("/d/xingxiu/tianroad4");
                          message("vision", "ֻ����������һ����˻��" + me->name() +  "������Ƕ��������˹��������Ƶ�������\n̴Ϫ�����¹���\n",
                          environment(me), ({me}) );
                          write("ֻ����������һ����˻���������Ƕ��������˹�����"
                          "���ǿ���ˡ�\n");
                          return 1;
                }
                else {
                	if (me->query_skill("zhaixinggong",1)>100){
                		if (me->is_busy())
                			return notify_fail("��������æ���أ���\n");
                		message_vision(HIY"$N�������Ṧ������һ�ݣ���ƮƮ��Խ�������\n"NOR, me);
                		me->move("/d/xingxiu/tianroad4");
                		message_vision(HIC"$N���˶��񣬾���������ˬ���ŵ�Ʈ������æ��ס�Ṧ��\n"NOR, me);
                		me->start_busy(random(3)+2);
                		me->improve_skill("dodge",random(me->query_skill("zhaixinggong",1)));
                		me->add("jingli",-100);
                	} else  write("�������ԣ���������Ǳ߱���߸ߣ�����������������ȥ�ġ�\n");
                        return 1;
                }
        }
}
