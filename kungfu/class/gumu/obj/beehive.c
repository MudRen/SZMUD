// beehive.c ����
// by April     01.08.26
// update by April 01.10.30


#include "ansi.h"

inherit COMBINED_ITEM;
void dest_ob2(object obj,object me);

int     auto_check(object me,object ob);

void create()
{
        set_name(HIW "�����" NOR, ({ "feng xiang", "beehive", "box", "xiang" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",     HIW"���ǹ�Ĺ��ľ�Ƶ�����䡣�������˵ģ���֪���ж�����䡣�����putdown,close,carry,destbox������䡣\n"NOR );
                set("base_unit", "��");
                set("value", 1000);
                set("material", "wood");
                set("no_sell", 1);
                set("no_give",0);
                set("no_get",1);
                set("base_weight",5000);
        }

        set("no_refresh", 1);

        set_amount(1);
        setup();
}

void init()
{
        object me = this_player();
        if ( me->query("id",1)!="sun popo" ) {
                set("no_drop",  "��ô���õĶ�����ô�������ء�\n");
                set("no_steal", "���������͵������\n");
        }

        add_action("do_open", "open");
        add_action("do_close", "close");
        add_action("do_putdown", "putdown");
        add_action("do_give","give");
        add_action("do_cai", "cai");
        add_action("do_dest", "destbox");

}

int do_putdown(string arg)
{
        object me, ob;
        me = this_player();
        ob = this_object();

        if(!arg || (arg != "feng xiang" && arg != "beehive" && arg != "box" && arg != "xiang"))    
                return 0;
        if (ob->query("down")) return notify_fail("���Ϳ�ˣ� \n");
        if( !ob) return notify_fail("�㲢û�����ŷ��䰡��\n");
        if(environment(me)->query("short") != "����") return notify_fail("���Ҳ������ʵĵط��ŷ��䣡 \n");
        if( ob->query("owner") != me ) return notify_fail("����ķ�����\n");
        if(present("feng xiang", environment(me))) return notify_fail("�����Ѿ��б����ڷ�������ˡ�\n");
        if( ob->query("lastplace") == environment(me)) return notify_fail("����������ɹ��ۣ�\n");

        ob = present("feng xiang", me);

        if(me->is_busy())
                return notify_fail("����æ����! \n");

        message_vision(HIB"$N������������һ����յأ�����ذѷ�����ڵ��ϡ�\n"NOR,me);

        ob->set("down",1);
        ob->move(environment(me));
        return 1;
}

int do_open(string arg){
        object me = this_player();
        object ob = this_object();
        string descrp;

        if(!arg || (arg != "feng xiang" && arg != "beehive" && arg != "box" && arg != "xiang"))    
                return 0;
        if (ob->query("open")) return notify_fail("���Ϳ�ˣ� \n");
        if( ob->query("owner") != me ) return notify_fail("����ķ�����\n");
        if(me->is_busy()) return notify_fail("����æ���أ� \n");
        if (!ob->query("down")) return notify_fail("����Ȱ��������£� \n");
        if (ob->query("open")) return notify_fail("������ſ����أ� \n");
//      if(query("bee_out")) return notify_fail("������Ⱥæ���أ�\n");

        remove_call_out("auto_check");
        call_out("auto_check", 5+random(5),me,ob);

        message_vision(HIG"$N����ش��������ţ����½½�����طɳ���������ȥ�ˡ�\n"NOR,me);

        ob->set("open",1);
        ob->set("lastplace",environment(me));
        ob->set("mi",1);
        
        return 1;
}

int do_close(string arg){
        object me = this_player();
        object ob = this_object();
        string descrp;

        if(!arg || (arg != "feng xiang" && arg != "beehive" && arg != "box" && arg != "xiang"))    
                return 0;
        if (!ob->query("open")) return notify_fail("���Ϳ�ˣ� \n");
        if( ob->query("owner") != me ) return notify_fail("������ķ�����\n");
        if(me->is_busy()) return notify_fail("����æ���أ� \n");
        if (!ob->query("down")) return notify_fail("����Ȱ��������£� \n");
        if (!ob->query("open")) return notify_fail("������Ź����أ� \n");
        if (me->query("jingli")<200) return notify_fail("���Ѿ���ƣ���ߣ��޷��ٻ��������ˣ� \n");

        message_vision(HIG"$N���������дʣ�һ������½½�����ض����˻�����$N��������������,�ѷ��䱳�����ϡ�\n"NOR,me);

        ob->set("open",0);
        ob->set("down",0);
        ob->move(me);

        me->receive_damage("jingli", 100+random(100), "��������ˣ�");

        remove_call_out("auto_check");

        return 1;
}


int auto_check(object me,object ob)
{
        int     lvl = me->query_skill("bee-training",1);
        
        if( environment(ob) != environment(me) ){
                ob->set("escaped",1);
                message_vision(HIR"����ʱ����ô���ˣ���䶼û�˹�������\n"NOR,me);
                return 0;
        }
        if (ob->query("mi")<40)
                ob->add("mi",1);
        if (ob->query("mi") > 25 && random(2)==0)
        {
                message_vision(HIW"������Ŵ�ת�������ӷ�������Ѿ�������,��Ӧ�û�ȥ�ˡ�\n"NOR,me);
                return 1;
                
        }
        else if (random(15) == 0)
        {
                if (random(3) == 0)
                {
                        message_vision("$N����һЩ�����һ���ط���ֵ����ţ�Ҳ����ʲôҩ�Ŀ��Բ�(cai yao)�ɡ�\n",me);
                        environment(me)->set("yaocai_h",1);
                }
                else
                {
                        message_vision("$N����һЩ�����һ���ط���ֵ����ţ�Ҳ����ʲôҩ�Ŀ��Բ�(cai yao)�ɡ�\n",me);
                        environment(me)->set("yaocai",1);
                }

        }
        else if (ob->query("mi")%2 == 0 && random(2)==0)
        {
                message_vision(HIY"$N���ﲻ�Ϸ�����������ָ��������Ч�ʵĲ��ۡ�\n"NOR, me);
                me->start_busy(random(3));
                me->add("jingli",-(20+random(30)));
                if (lvl < 600)
                me->improve_skill("bee-training",lvl/3+random(lvl/2));
                me->improve_skill("force",lvl/5+random(lvl/3)); 
                
        }
        
        call_out("auto_check",5,me,ob);
        return 1;
}

int do_give(string arg)
{
        string target, item;
        object obj, who,ping, me=this_player();
        string msg;
        int     exp,qn,i,j;
        object *inv;
   

    if(!arg) return notify_fail("��Ҫ��˭ʲô������\n");

    if( sscanf(arg, "%s to %s", item, target)==2
        || sscanf(arg, "%s %s", target, item)==2 );
    else return notify_fail("��Ҫ��˭ʲô������\n");

        if ( item != "beehive" && item !="box" && item != "xiang" ) return 0;
        if ( target != "sun" && target !="nanny" ) return 0;
        if ( !objectp(obj = present(item, me)) ) return notify_fail("������û������������\n");
        if (me->is_busy()) return notify_fail("����æ���ء�\n");
    if (!objectp(who = present(target, environment(me))) || !living(who))
        return notify_fail("����û������ˡ�\n");
        if ( userp(who) ) return notify_fail("�Է�����������������\n");
        if ( who->query("race") != "����" )
                return notify_fail("���Ҳ������ô������佻��������\n");
        if( who == me) return notify_fail("�Լ����Լ�����\n");

        message_vision("$N��$nһ��"+HIW"����䡣\n"NOR, me, who);

        if ( obj->query("owner") == me ) 
        {
                if(query("escaped")) {
                        message_vision(CYN"$N������˼��ɦ��ɦͷ��\n"NOR, me, who);
                        message_vision(CYN"$N��������������˵������ι���û�ɺá�\n"NOR, me, who);
                        message_vision(CYN"$n����������$N��ͷ��\n"NOR, me, who);
                        message_vision(CYN"$n�Ͱ��ض�$N˵����û��ϵ���´�ע��ͺá�\n"NOR, me, who);
                        if(me->query_temp("gm_xunfeng",1) ) me->delete_temp("gm_xunfeng");
                }
                else if (obj->query("mi") < 25)
                {
                        message_vision(CYN"$n˵��������û�в�������û��ϵ���´�ע��ͺá�\n"NOR,me,who);
                        if(me->query_temp("gm_xunfeng",1) ) me->delete_temp("gm_xunfeng");
                }
                else
                {
                        message_vision(CYN"$n����������$N��ͷ��\n"NOR, me, who);
                        message_vision(CYN"$n�Ͱ��ض�$N˵��������$N������ȥ��Ϣһ�°ɡ�\n"NOR, me, who);
                        exp = 180+random(40);
                        qn = 60 + random(40);
                        msg=sprintf(HIW"����������񹲵õ�:%d����,%dǱ�ܡ�\n"NOR,exp,qn);
                        tell_object(me,msg);
                        if(me->query_temp("gm_xunfeng",1) ) me->delete_temp("gm_xunfeng");
                        me->add("combat_exp",exp);
                        me->add("potential",qn);
                        if (me->query("potential") > me->query("max_potential"))
                        me->set("potential",me->query("max_potential"));
                        
                        if (random(1)==0)
                        {
                                inv = all_inventory(me);
                                j=0;
                                for(i=0; i<sizeof(inv); i++)
                                        if( inv[i]->query("name") == CYN"���ƿ"NOR )
                                        j += 1;
                                if (j > 4)
                                tell_object(me,"�����Ŷ���˵�����Ѿ��кö����ƿ�ˣ��ҾͲ������ˡ�\n");
                                else if (random(5)==0)
                                {
                                        ping = new("/kungfu/class/gumu/obj/qingci-ping");
                                        ping->set("liquid/remaining",10);
                                        ping->set("liquid/name","�������");
                                        ping->move(me);
                                        tell_object(me,"�����Ÿ���һƿ���������\n");

                                }
                                else
                                {
                                        ping = new("/kungfu/class/gumu/obj/qingci-ping");
                                        ping->set("liquid/remaining",10);
                                        ping->move(me);
                                        tell_object(me,"�����Ÿ���һƿ����ۡ�\n");
                                
                                }
                        }
                }
        
        }
        else 
        {
                message_vision(CYN"$n��$N΢΢Ц��Ц��\n"NOR, me, who);
                message_vision(CYN"$n˵������л����\n"NOR, me, who);
        }

        destruct(obj);
        
        return 1;
}

int do_cai(string arg)
{
        object me = this_player();
        object here = environment(me);
        int i;
        object yaocai;

        if ( !arg && arg != "yao" ) return 0;
        if ( !here->query("yaocai") && !here->query("yaocai_h") ) return 0;

        if (here->query("yaocai")){
                here->set("yaocai",0);
                switch (random(5)){
                case 0 : yaocai = new("/clone/herb/chantui");
                        break;
                case 1 : yaocai = new("/kungfu/class/gumu/herb/muxiang");
                        break;
                case 2 : yaocai = new("/kungfu/class/gumu/herb/shengma");
                        break;
                case 3 : yaocai = new("/kungfu/class/gumu/herb/chaihu");
                        break;
                case 4 : yaocai = new("/kungfu/class/gumu/herb/shanju");
                        break;
                }
                yaocai->move(me);
                message_vision("$N�����Ӳݷ�����"+yaocai->query("name")+"��\n", me);
        }
        if (here->query("yaocai_h")){
                here->set("yaocai_h",0);
                switch (random(3)){
                case 0 : yaocai = new("/clone/herb/renshen");
                        break;
                case 1 : yaocai = new("/clone/herb/heshouwu");
                        break;
                case 2 : yaocai = new("/kungfu/class/gumu/herb/tufuling");
                        break;
                }
                yaocai->move(me);
                message_vision("$N�����Ӳݷ�����"+yaocai->query("name")+"��\n", me);
        }
        return 1;
}
int do_dest(string arg){
         object obj;
         object me = this_player();

         if (arg != "box" && arg != "xiang" )
                return notify_fail("��ֻ�ܴݻٷ��䡣\n");
         obj = present(arg, environment(me)); 
         if (!obj)  return notify_fail("��ֻ�ܴݻ��Լ��ķ��䡣\n");
         if ( obj->query("owner") != me || !obj )
                return notify_fail("��ֻ�ܴݻ��Լ��ķ��䡣\n");
         if (obj)
         {
                   message_vision(HIG"$N������������Ѿ������ˣ�һ�Ű������˸����顣\n"NOR,me);
                   call_out("dest_ob2",1,obj,me);
         }
         else return notify_fail("û������������������\n");
         return 1;
}
void dest_ob2(object obj,object me)
{

                   destruct(obj);
}
