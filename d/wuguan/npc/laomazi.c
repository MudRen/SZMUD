// ������100�����II
// xiaoer.c ƽ���ǵ�С��
// ����lywin 2000/6/1 ��ͯ��
// recode by sinan@sz 2002_3_29
// �����������̣���������������С��������(ask xiao about job)��
// Ȼ����С��Ҫ����(ask xiao about panzi)��С������һЩ�����Ժ�
// ������ȥϴ�ɾ�����(xi panzi),ϴ�ɾ��󽻸�С����������ɣ��õ�
// ������
// ��С������Ϊ�����ӣ�filename: /d/wuguan/npc/laomazi.c  sinan@sz 02-4-8

#include <ansi.h>
#include <command.h>
inherit NPC;

int ask_done();
int do_gongzuo();
string ask_panzi();

void create()
{
        set_name("������", ({"lao mazi", "lao"}));
        set("gender", "Ů��");
        set("age", 55);
      set("long", 
              "��������ݵĳ�ʦ�����ӡ�\n");
        set("qi", 100);
        set("max_qi", 100);
        set("jing", 100);
        set("max_jing", 100);
        set("per", 25);
        
        set("combat_exp", 1500);
        set("score", 200);
        
        set("inquiry", ([
                "����" : (: do_gongzuo :),
                "job"  : (: do_gongzuo :),
                "work" : (: do_gongzuo :),
                "����" : (: ask_panzi :),
                "panzi": (: ask_panzi :),
                "done": (: ask_done :),
                "over": (: ask_done :),
                "���": (: ask_done :),
        ]) );
        setup();
        carry_object("clone/armor/cloth")->wear();
}

int do_gongzuo()
{      
        object me;
        me = this_player(); 
        
        if (me->query("combat_exp") >= 5000) {
                tell_object(me,"���С����ô�������Ĵ�ݡ�\n");
                return 1;
        }  
        if( me->query_temp("gongzuo/xipanzi") > 0) {
                tell_object(me,"��ȥϴ���Ӱɡ�\n");
                return 1;
        }  
        
                tell_object(me,CYN"�����Ӷ���˵�����⼸����˶࣡����ϴ����������Ը��ɵĻ������԰���ϴ���ӡ�\n"NOR); 
        me->set_temp("gongzuo/xipanzi", 1);
        
        return 1;   
}

string ask_panzi()
{
        object me,ob;
        me = this_player(); 
        if( me->query_temp("gongzuo/xipanzi")< 1)
                return "����Ҫ�����Ļ���Ҳ�ú��Ҵ���к��\n";
                
        if( me->query_temp("gongzuo/geipanzi")> 0)
                return "�Ҳ��Ǹ��������������ѵ��㶪������";
                
        ob = new("/d/wuguan/obj/zangpanzi");
        ob->move(me);
        me->set_temp("gongzuo/geipanzi", 1);
        message_vision("�����Ӹ���$Nһ�������ӡ�\n",me);
        return "�ðɣ����ȥ����ϴ�ϸɾ���Щ���Ӱɡ�";
}

/*
void accept_object(object me, object ob)
{
        int exp,pot;

        if ( (int)me->query("combat_exp") > 5000)
                command("say ���ֻ���������Ĵ����ɵġ�\n");
                                
        if ( me->query_temp("gongzuo/xipanzi") < 1 ) {
                command("say ��û������Ҫ�������ɡ�\n");
        }
        
        else if ( ob->query("name") != "����" ) {
                command("say ����ϴ�õ����ӣ��㲻�ǿ���Ц�ɣ�\n");
        }
        
        else
        {
                message_vision(CYN"�����Ӷ�$N˵���������ˡ�����������
                        ��ľ�����������һЩ��\n"NOR,me);
      
                me->delete_temp("gongzuo");
               me->add("combat_exp",exp = 30 + random(40) );
                me->add("potential",pot = 10 + random(20) );
               log_file("xipanzi", me->query("id")+"�õ�"+exp+"�㾭��"+pot+"��Ǳ��"+"["+ctime(time())+"]\n" );
//                call_out("destroying", 1, this_object(), ob);
        }
}
void destroying(object me, object obj)
{
//        destruct(obj);
        return;
}
*/
int ask_done()
{
        int exp,pot;
        object ob,me;
        me=this_player();
        
        if ( (int)me->query("combat_exp") > 5000)
                return notify_fail("���ֻ���������Ĵ����ɵġ�\n");
                                
        if ( me->query_temp("gongzuo/xipanzi") < 1 ) {
                return notify_fail("��û������Ҫ�������ɡ�\n");
        }
        
        else if ( !( ob = present("pan zi", this_player() )) ) {
                return notify_fail("������Ӹ㶪�ˣ�\n");
        }
        
        else
        {
                message_vision(CYN"�����Ӷ�$N˵���������ˡ�����������
                        ��ľ�����������һЩ��\n"NOR,me);
                
                destruct(ob);
                
                me->delete_temp("gongzuo");
                me->add("combat_exp",exp = 30 + random(40) );
                me->add("potential",pot = 10 + random(20) );
     if(me->query("potential")>me->query("max_potential")) 
      me->set("potential",me->query("max_potential")); 
                
                log_file("xipanzi", me->query("id")+"�õ�"+exp+"�㾭��"+pot+"��Ǳ��"+"["+ctime(time())+"]\n" );
                
                return 1;
        }
}
