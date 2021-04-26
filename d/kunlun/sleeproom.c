// sleeproom.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
set("short","����");
        set("long",@long
�����Ǻ�̫����谮�ĵ���С���õ��Է�����һ�������˱Ǳ���һ��ҩ
�������滹���ŵ�һ��ʮ�ֹŹֵ���Ϣ������Ƭ�̣�����������Ϣ��Ũ������
�������ء���������һ���ˣ�������������������������ǳ��ŷ��䡣��
��(window)���ǽ������š�
long);

set("item_desc", ([
"window" : "������ƣ��㲻����򿪴���͸͸����\n",
"��" : "һ���ľ��齣���ǽ�Ĵ��ű���һС��(hole)��\n",
    "hole" : "һ��ֻ��Ĵָ����С�������߷ǳ��⻬���ƺ������ж������롣\n",
]));

set("objects",([
 "/kungfu/class/kunlun/zhanchun.c" :   1,
   "/d/kunlun/npc/wugu.c" : 1,
]));

set("exits", ([
"east" : __DIR__"tieqinju",
]));
          set("no_clean_up", 0);
create_door("east", "С��", "west", DOOR_CLOSED);
          setup();
}

int she_come(object me)
{
   object ob;
   if (!me || environment(me)!=this_object()) return 1;
   ob=new( "/d/kunlun/npc/jinguanshe");
   ob->move(this_object());
   ob=new( "/d/kunlun/npc/yinguanshe");
   ob->move(this_object());
   if (present("xionghuang", me) && objectp(present("wu gu",this_object()))){
        message("vision","������ӰͻȻ��С�������˳�����������齣�һ��ҧס��õĽ�ָ��\n",this_object());
        call_out("wugu_bian",3,me); 
        }
   else 
   message("vision","������ӰͻȻ��С�������˳�����\n",this_object());
}
void init()
{
    if (objectp(present("wu gu",this_object())))
        set("long", @LONG
һ���ţ��˱Ǳ���һ��ҩ����һ����齷���ǽ�ǣ�����ϸɴ���ҿ����ӣ�ֻ
��һ�����׵����Ϲϰ��Ů�����ڴ��ϡ�
LONG
        );
        else
        set("long", "һ���ţ��˱Ǳ���һ��ҩ����һ����齷���ǽ�ǣ�����ϸɴ��\n");
}
void wugu_bian(object me)
{
        object ob,masterhe,room;
        if (!me || environment(me)!=this_object() ) return;
        if (objectp(ob=present("wu gu",this_object()))){
                ob->set("per",35); 
                ob->set("long","���Ǻ�̫�������̫��\n");
                set("long", @LONG
һ���ţ��˱Ǳ���һ��ҩ����һ����齷���ǽ�ǣ�����ϸɴ��һλ��ɫ������
�����ӣ������ڴ�����ͷ��
LONG
                );
                  masterhe=find_living("he taichong");
                if (masterhe && environment(masterhe)){
                        message("vision",masterhe->name()+"����ææ�߿��ˡ�\n",environment(masterhe));
                        masterhe->move(this_object());
                        message("vision",masterhe->name()+"�˳������˽�����\n",this_object());
                        message_vision(HIC "$N����$n"+HIC+"���֣������ĬĬ���ӡ�Ŀ�����к���ǧ�����飬������⡣\n"+NOR,masterhe,ob);
                          if ((string)me->query("family/family_name")=="������"){
                                message_vision(CYN "$N��$nЦ������λ"+RANK_D->query_respect(me)+"�κ����Ұ�檵Ĳ����������Իر�...\n" NOR,masterhe,me);
                                message_vision("$N�������ó�һ���飬������$n��\n",masterhe,me);
                                ob=new("/d/kunlun/obj/lyj-book");
                CHANNEL_D->do_channel(me, "rumor", sprintf("%sŪ��һ�����ǽ��ס�", me->query("name")));
                                ob->move(me);
                                message_vision(CYN "$N��$n˵����СС������ɾ��⡣\n" NOR,masterhe,me);
                        }else{
                                if (!(room=find_object(__DIR__"mw")))
                                        room=load_object(__DIR__"mw");
                                message_vision(CYN "$N��$n˵�����ѵ������������ĵ��ӡ�\n" NOR,masterhe,me);
                                message_vision("$N����һ�ӣ������ھ�������齻����ƿ�...\n¶��һ�����ڡ�\n",masterhe);
                                message_vision("ͻȻ�Ӷ�������һ��������$N���в��ã����ǲ��������ص�������...\n",me);
                                me->move(room);
                                message("vision",me->name()+"ͻȻ��������¡�\n",room,({me}));
                                message_vision("$N΢΢һЦ����������齻����ƻ�ԭ����\n",masterhe);
                        }
                }
        }
}
