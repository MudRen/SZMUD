// Code of ShenZhou
// coding by Slow
#include <ansi.h>
inherit NPC;

int auto_perform();
void you_out();
void create()
{
          set_name("����", ({"xiao feng", "xiao", "feng"}));
          set("nickname", "����");
        set("gender", "����");
          set("age", 35);
        set("long", 
"������ǿ�ΰ����ʮ������ͣ�����ɫ�ɲ��ۣ���΢�����ã�Ũü���ۣ�
�߱����ڣ�һ���ķ��Ĺ����������з�˪֮ɫ������֮�ʣ��������ơ�\n");
        set("attitude", "peaceful");
        
         set("str", 30);
         set("int", 24);
         set("con", 40);
         set("dex", 40);
              set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                    (: auto_perform :),
        }) );

          set("max_qi", 10000);
        set("max_jing", 3000);
          set("neili", 10000);
          set("max_neili", 10000);
          set("jingli", 10000);
          set("max_jingli", 9000);
          set("eff_jingli", 9000);
        set("jiali", 100);
        
               set("combat_exp", 5400000);

        set("score", 200000);
            set("death_times",200);

        set_skill("force", 400);             // �����ڹ�
        set_skill("huntian-qigong", 400);    // ��������
        set_skill("strike", 400);            // �����Ʒ�
        set_skill("xianglong-zhang", 400);   // ����ʮ����
        set_skill("dodge", 400);             // ��������
        set_skill("xiaoyaoyou", 400);        // ��ң��
        set_skill("parry", 400);             // �����м�
        
        map_skill("force", "huntian-qigong");
        map_skill("strike","xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
          map_skill("parry", "xianglong-zhang");
        prepare_skill("strike", "xianglong-zhang");
               create_family("ؤ��", 13, "����"); 
        setup();
        
        carry_object("/d/gaibang/obj/budai")->set_amount(9);
        carry_object("/d/gaibang/obj/budai")->wear();
}
int accept_kill(object victim)
{
         object *ob;
           int i;
           object me=this_object();
        if(victim->query_temp("azi/killer")!=1 && victim->query_temp("azi/killer2")!=1)
         {
          command("say �����а��֣�������ĳ��ʱ�¹��˶࣡\n");
       message_vision(HIY "��������˰��֣���������,�ѽ���ʮ���Ʒ��ӵ�����,ֻ������˫�ۻ�Ȧ�Ƴ�������һ�С������лڡ�!\n" NOR,me);
        command("halt");
              ob = all_inventory(environment(me));
              for(i=0; i<sizeof(ob); i++) {
              if(living(ob[i])  && ob[i]->query_temp("azi/killer2")==1) {
              tell_object(ob[i], "��е�һ��ǿ�ҵ�����ӿ���ؿڣ��ؿ�һ�ơ�\n");
              ob[i]->unconcious();
              }
           }
              tell_object(victim, "��е�һ��ǿ�ҵ�����ӿ���ؿڣ��ؿڵ�ʱһ�ơ�\n");
              if (victim) victim->unconcious();
        call_out("destruct_me",1,me);
        me->start_busy(5);
          }
          return 0;
}
void die()
{
          object  me =this_object();
          object  ob;
           message_vision(HIR"�����:����,�������,�����������ˣ�\n" NOR,this_object());
/*
            ob = me->query_temp("last_damage_from");
          if(!find_living("you tanzhi"))
          {
          ob->delete("azi/killer");
          ob->delete("azi/killer2");
          }
*/
              you_out();
               ::die();
}
void destruct_me(object me)
{
          object obj;
        obj=find_object("a zi");
        if (!obj) obj = present("a zi", me);
        if (!obj) obj = present("a zi", environment(me));
//        if (!obj) obj = find_object( resolve_path(me->query("cwd"), "a zi") );
          if (obj)
         {
          destruct(obj);
message_vision(HIY"���������Ц����:�����Ķ��Ȳ�������ס���ϣ��������䣬���Ѳ�����\n" NOR,this_object());
         destruct(me);
          }
}
void you_out()
{
        object ob1,ob2,player;
         object me=this_object();
       player=me->query_temp("last_damage_from");
         ob1=present("you tanzhi");
         if (!ob1)
         {
             seteuid(getuid());
                 ob1=new("/d/quest/xingxiu/npc/you.c");
             ob1->move(environment());
           }
}
// void init(){ set_heart_beat(1);}
#include "/kungfu/class/xingxiu/newhuajob_perform.h"

