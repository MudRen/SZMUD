// Code of ShenZhou
// Modified by xbc; add quests 06/21/97
// Modified by xuy; fixed crashing bugs in quests 08/11/97
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
int do_chi(string arg);
int do_chaikai();

void create()
{
        set_name("���߹�", ({"hong qigong", "hong", "qigong"}));
        set("nickname", "��ָ��ؤ");
        set("gender", "����");
        set("age", 75);
        set("long", 
"��һ�ų����������΢�룬���ִ�ţ������·���һ����һ��Ĵ����˲�����
ȴϴ�øɸɾ��������ϸ��Ÿ������Ĵ��«��\n");
        set("attitude", "peaceful");
        
        set("str", 35);
        set("int", 24);
        set("con", 30);
        set("dex", 30);

        set("rank", 10);
/*
        set("chat_chance", 1);
        set("chat_msg", ({
                "���߹����Ŷ�Ƥ̾�����������þ�û�Ե��ض��յ�С���ˡ�����\n",
        }));
        set("inquiry", ([
                "������" : "�Ͻл���û�������ô�����£���ȥ������С��ɣ�\n",
        ]));

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
*/
        set("max_qi", 4000);
        set("max_jing", 3000);
        set("neili", 5500);
        set("max_neili", 5500);
        set("jiali", 0);
        
        set("combat_exp", 3600000);
        set("score", 200000);
        set("death_times",180);

        set_skill("force", 400);             // �����ڹ�
        set_skill("huntian-qigong", 400);    // ��������
        set_skill("strike", 400);            // �����Ʒ�
        set_skill("xianglong-zhang", 400);   // ����ʮ����
        set_skill("hand", 360);              // �����ַ�
        set_skill("shexing-diaoshou", 400);  // ���ε��� 
        set_skill("dodge", 400);             // ��������
        set_skill("xiaoyaoyou", 400);        // ��ң��
        set_skill("parry", 400);             // �����м�
        set_skill("stick", 400);             // ��������
        set_skill("dagou-bang", 400);        // �򹷰���
        set_skill("begging", 200);           // �л�����
        set_skill("checking", 200);          // ����;˵
        set_skill("training", 240);          // Ԧ����
        set_skill("digging", 200);  
        
        map_skill("force", "huntian-qigong");
        map_skill("strike","xianglong-zhang");
        map_skill("hand",  "shexing-diaoshou");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "dagou-bang");
        map_skill("stick", "dagou-bang");
        
        prepare_skill("strike", "xianglong-zhang");

        create_family("ؤ��", 17, "����");
        setup();
        
        carry_object("/d/gaibang/obj/budai")->set_amount(9);
        carry_object("/d/gaibang/obj/budai")->wear();
        if (clonep()) carry_object("/d/gaibang/obj/dahulu"); 
}

void init()
{
        object ob, me;
        ::init();
        
        ob = this_player();
        if (interactive(ob) && !is_fighting() && !ob->query("questwg"))
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object me)
{
        object ob = this_object();
        command(HIW"say ���������Ҳ��ᣬ���������˵ ��"NOR);
        message_vision(HIW"\n
$N֧����������һ��ѩˮ���ִ�һ�����ʯ�ߵ��������ڳ�һֻ����������
$n��ѩ����ӳ���Ƶ÷�����ֻ��������ҧ���˰������߰˴糤�Ĵ���򼣬���
��䣬���ư�쵣��������������$N��ס���β�ͣ�һ���������ڹ��
��Щ�������һ�󣬱㶼�������ˡ�\n
$N�������͹��������ȥ��ը��΢��֮��������ϰ��ȣ���������������
һ������������У�������˼���������΢�գ�̾��һ������ֻ������֮���֣�
�����ڴ��ӡ�\n
���߹�����ʮ�����Ժ���$n�������Ҽ�������Ӣ�ۺú���ɱͷ��Ѫ������ü
ͷ��ȴûһ���Ҹ����Ͻл���һ����򼡣С���ޣ���Ҳ��ҳԣ�chi������\n\n
"NOR,ob,me);
        
        add_action("do_chi","chi");
        
        return;
}
int do_chi(string arg)
{
        object me=this_player();
        object ob=this_object();
        if (!arg)
        return notify_fail(HIW"��Ҫ��ʲô��\n"NOR);
        if (arg == "wugong")
        {
                remove_action("do_chi","chi");
                message_vision(HIW"
$N��һ�������ڿ���һ����ֻһ������ȥ�����������������ִ����㣬����
��Ũ��һ��֮�д�δ���������ζ���ٽ��˼��ڣ�һ��µ������ȥ����ȥЮ��
�������ԣ����ޣ�����������\n"NOR,me);
                call_out("feng_out",5,ob,me);
        }
        else 
        return notify_fail(HIW"û������������\n"NOR);

        return 1;

}
void feng_out(object hong,object me)
{
        object feng;
        feng=new("/u/slow/questwg/feng");
        feng->move("/u/slow/questwg/jueding5");
        message_vision(CYN"
���������Ҷ�Ե���������ֻ���졢�졢�켸���죬ɽ�Ǻ�ת����һ�ˣ���
�ӵߵ���˫�ָ���ʯ�飬�ŵض��У���������ŷ���档ŷ���������˵�����
�߹����𹥻���\n\n"NOR,me);
        feng->kill_ob(hong);
          call_out("chai_out",10,hong,feng,me);

}

void chai_out(object hong,object feng,object me)
{
        
        feng->remove_all_killer();
        message_vision(HIW"
ŷ����ͻȻ���������ȣ�˫��һ�䣬�������������󡱵�һ����У�������
��������˫���뷢����ǰ�Ƴ�����һ��ʵ������������֮���ۡ����߹��;���
����������֪���Ҳ��˫����ǰƽ�ơ���һ������Ӳ��Ӳ��ɲ��֮�䣬����
�ﾹȻ��ס������\n
���˽���һ�ᣬŷ����ͷ��͸��һ���Ƶİ���������Խ��ԽŨ����������һ�㡣
���߹�Ҳ��ȫ�����������ۼ�������ɫ��䣬�������������յ�һʱ���̣���
ͬ���ھ����ɣ�������ǰ�𿪣�chaikai�����Լ��������������̫Զ �����
�ֽⲻ�������������Լ�һ��������\n\n"NOR,feng,hong);
        add_action("do_chaikai","chaikai");
        call_out("chaikai_out",8,hong,feng,me);
}
int do_chaikai()
{
        object me=this_player();
        object hong =  this_object();
        object book;    
        object feng;

        feng = present("ouyang feng", environment(me));

        if (me->query("max_neili")<8000  || me->query("neili") <10000)
        {
                message_vision(HIC"
$N����һ�����ɣ��ߵ�����֮����ϥ���£��˹���סȫ��һҧ������������
����֮����ȥ��$Nֻ��һ�ɴ����������ϴ����������������緭�������㣬$N
������ߵķ��ݰ�ֱ׹��ɽ�¡�\n"NOR,me);
                me->move("/d/huashan/sheshen");
                me->unconcious();
        }
        else 
        {
                message_vision(HIC"
$N����һ�����ɣ��ߵ�����֮����ϥ���£��˹���סȫ��һҧ��������������
��֮����ȥ����һ����Ȼ�������������˵������������ϴ�������$N������һ����
����жȥ��ԭ��ǿ��֮ĩ���ܴ�³�ɣ���ؤ������Ȼ���ǵ���֮�ۣ������Ķ�ʱ��
���Ѿ����޶ࡣ\n"NOR,me);
                hong->set("chaikai",1);
                tell_object(me,HIM"
��Ӻ��߹���ŷ�����ս���л����ǳ��\n"NOR,me);
                  me->add("combat_exp",(30000+random(20000)));
                me->set("questwg",1);
                if (me->query("family/family_name") == "ؤ��") 
                {
                          me->set("questwg",1);
                        tell_object(me,HIW"
ŷ���������Ц���е����������㶷�˼�ʮ�꣬������ֻ�Ǵ��ƽ�֣��Ͻл���
���˵ã����漴ƮȻ��ɽ��\n
���߹��������������һ���书�����㡣���书����ֻ������������������ˣ�
����������Ե���ҾͰѿھ����ڸ��㡣�Ȿ������Ŵ򹷰������һ�С�������
���������Ժ���Ҫ���飬����ؤ���ܶ����ҡ���\n\n\n"NOR);
                        
                        book=new("/u/slow/questwg/dgb_book");
                        if (book)
                       {
                          book->move(me);
tell_object(me,HIY"��õ�һ�����򹷰��ס���\n\n"NOR);
                        }

                }
                
                message_vision(HIW"
���߹��������˴��캮�ض���С���޲��˾�������������һͬ��ɽ�������߹�Я��
$n���֣��������䣬��Ծ�·嶥��\n\n "NOR,hong,me);
                me->move("/d/huashan/sheshen");
                tell_object(me,HIW"
���߹������Ķ�Ƥ����������Ͻл�Ҫ�Ա�������ʳ����������ͬ���ˣ������Ϊ
֮�ɣ���ֻ����Ӱ�ζ�����ʱ���ȥ����Ӱ���١�\n\n "NOR,hong,me);
                call_out("all_dest",1,feng,hong);
                
                

        
        }
        return 1;
}

void chaikai_out(object hong,object feng,object me)
{
        if (!hong->query("chaikai"))
        {
                message_vision(HIR"
$N��$n����ͻȻͬʱί���ڵأ�˫Ŀ���գ��������ң�һ��Ҳ�����ˣ�
ԭ�������Ѻľ�������������ؤ������ʮ���������񶷣��������£���֪��ͬ
ʱ�ڻ�ɽ��������,��ֻ����Ȼ��ɽ��\n"NOR,hong,feng);
           me->move("/d/huashan/sheshen");
        
                feng->die();
                hong->die();
        }
}
void all_dest(object feng,object hong)
{
        destruct(feng);
        destruct(hong);

}
