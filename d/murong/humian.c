// Code of ShenZhou
//ROOM: /d/murong/humian
//arthurgu 1999.9

inherit ROOM;
string look_zhuang();
void init();

void create()
{       set("short", "����");
        set("long", @LONG
    ����⻬�羵����ϸ��ȥ��ˮ��������ԼԼ����Щ
�������ľ׮(zhuang)������Ľ���ϵ��Ӿ�����������
ϰ�Ṧ��
LONG  
    );           
  
        set("outdoors", "murong");

	set("exits", ([ 
        "northwest" : __DIR__"lianwu",
                     ]));

        set("item_desc",([
                         "zhuang" : ( :look_zhuang:),                        ]));
        setup();
       }
 
string look_zhuang()
{ return "һ����ľ׮�����ں��ף�������ֻ����ԼԼ¶��\n"
        "һЩ���ߡ��㲻֪����Щľ׮ͨ���δ��������ȥ\n"
       "�Ļ�����֪�����������\n";}

void init()
{
       object ob=this_player();

        if (userp(ob) && !wizardp(ob) && ob->query("family/family_name") != "����Ľ��") {
                message_vision("�ſͺȵ�����$N�㲻����Ľ�ݼҵ��ˣ���ô�����������ˣ���ȥ��\n",ob);
                remove_call_out("kickout");
                call_out("kickout", 1, ob);
        }

        add_action("do_go", "go");
}

int kickout(object ob)
{
        if (!present(ob,find_object("/d/murong/chufang.c"))) {
                return 1;
        }
        message_vision("�ſͰ�$N���˳�ȥ��\n",ob);
        ob->move("/d/murong/qing1");
        message("vision","ֻ����"+ob->query("name")+"���������ش��������˳�����\n", environment(ob), ob);
        return 1;
}


int do_go(string arg)
{
        object me;
        me = this_player () ;

       if ( !arg || ( arg != "zhuang" ) )
                return notify_fail("ʲô��\n");
   
        if ( (int)me->query("neili") < 80)
        return notify_fail ("$N�������������ľ׮�������е㷢�ţ�æ���˻�����\n");

         if ( (int)me->query("combat_exp") <10000)
        {
        me->receive_damage("qi", 50, "��������������");
                me->receive_wound("qi",  50, "��������������");
                message_vision("$Nֻ���ý���һ�����ģ�... 
��...��\n", me);
                tell_object(me, 
"��������������Ŭ��������ľ׮�������������ᡣ\n");
                message("vision", "ֻ��" + me->query("name") + 
"�Ӻ���ʪ��������������ɫ�԰��Ѽ���\n", environment(me), me);
          return 1;
        }

         me->add("jingli", (-1)*random(50), "������");
         me->add("neili", (-1)*random(50));
               
        message_vision("$N�ŲȰ��Է�λ���ߵ÷ɿ졣\n", me);

     if ( (int)me->query_skill("dodge", 1) >= 120)
       { me ->move("/d/murong/mantuo1");
       tell_object(me, "\n�㽡����ɣ���һ����ߵ�����ɽׯ...\n\n" ) ;
        return 1 ;
        }
    else if ( (int)me->query_skill("dodge", 1) < 120)
        me->improve_skill("dodge", me->query("dex")); 
        write("������һ���ľ׮���е��Ƚ��е���ʹ��\n");                      
       return 1;
}
 


 
