// Code of ShenZhou
// coding by Slow
#include <ansi.h>
inherit NPC;

int auto_perform();
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
        
         set("str", 40);
         set("int", 24);
         set("con", 40);
         set("dex", 40);

            set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                    (: auto_perform :),
        }) );

          set("max_qi", 15000);
        set("max_jing", 3000);
          set("neili", 15500);
          set("max_neili", 15500);
          set("jingli", 10000);
          set("max_jingli", 10000);
          set("eff_jingli", 10000);
        set("jiali", 300);
        
          set("combat_exp", 8000000);
        set("score", 200000);
            set("death_times",200);

        set_skill("force", 400);             // �����ڹ�
        set_skill("huntian-qigong", 400);    // ��������
        set_skill("strike", 400);            // �����Ʒ�
        set_skill("xianglong-zhang", 450);   // ����ʮ����
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
           object me=this_object();
          if (victim->query("azi/killer2")!=1)
         {
          command("say �����а��֣������ߣ�\n");
           call_out("destruct_me",1,me);
          }
          return 0;
}
void die()
{
           message_vision(HIR"�����:����,�������,�����������ˣ�\n" NOR,this_object());
               ::die();
}
void destruct_me(object me)
{
          object obj;
        obj=find_object("a zi");
        if (!obj) obj = present("a zi", me);
        if (!obj) obj = present("a zi", environment(me));
        if (!obj) obj = find_object( resolve_path(me->query("cwd"), "a zi") );
message_vision(HIY"����ͻȻ���Ʊ�ס���ϣ��������䣬���Ѳ�����\n" NOR,this_object());
          if (obj)
          destruct(obj);
         destruct(me);
}
// void init(){ set_heart_beat(1);}
#include "/kungfu/class/xingxiu/newhuajob_perform.h"
