#include <ansi.h>
string ask_me()
{

        object asker,me;
        asker = this_player();
        me = this_object();
        if ( asker->query_skill("lamaism") < 51 )
                                        return RANK_D->query_respect(asker) + "�����𷨣����������ӵܡ�"; 
        if ( me->query("assigned_asker") )
                                        return RANK_D->query_respect(asker) + 
        "������������ʩ�����ˣ����һ��ʱ�������ɡ�";
        say("\n���»��˵������ʦ��Ԩ��ֿ��ڶ��ˣ���������֮������\n");
                me->set("assigned_asker", asker->query("id"));            
                message_vision("\n���»����һ����һ�������������ֳ�һ���ķ���̨��\n\n", asker);
                                        return "������׼�����ˣ��뽫��ͽ�������ġ�\n";
}

int accept_object(object ob, object obj)
{
        mapping fam;
        object me = this_object();
        int obj_exp,my_exp,got_pot,shen;
        shen = obj->query("shen");
        if (ob->query("id")!=me->query("assigned_asker"))
                                return notify_fail("���������������ģ���ƭ������\n");
        if (shen <=1)
                        {
                        say("����ʲô��˼����ò��ͷ��ˣ�\n");    
        me->delete("assigned_asker");    
        me->kill_ob(ob);
                                return 1;
                        }
        if (userp(obj)==1)
                        {
                                me->delete("assigned_asker");       
                    return notify_fail("������Ҵ�ͨ���ף���Ϊ������ɵ�ϣ�\n");
            }
        obj_exp=(int)obj->query("combat_exp",1);
        my_exp=(int)ob->query("combat_exp",1);
        if (my_exp>obj_exp*2)
                        {
                    me->delete("assigned_asker");       
                    return notify_fail("���Ҹ�С������Ȱ����δ��̫ʧ��ݡ�\n");
                    }
         message("vision", HIY"\n���»��˫��һ�ӣ��ѽ�"+obj->query("name")+"������̨�����ܷ��״�����\n"NOR,  environment(ob),ob);
         write (HIY"���»��˫��һ�ӣ��ѽ�"+obj->query("name")+"������̨�����ܷ��״�����\n"NOR); 
         message(HIR "vision", ob->name()+HIR"����ҡ�����ƣ��Ż���ɣ����׶�Ϣ��\n",environment(ob),ob);
         write("������ҡ�����ƣ��Ż���ɣ����׶�Ϣ��\n"NOR);
         message("vision", ob->name()+"�������д�˰������ģ�һƬ��������ŷ�̨��\n",environment(ob),ob);
         write ("��������д�˰������ģ�һƬ��������ŷ�̨��\n");
         message("vision",ob->name()+"һ���Ϻȣ��Ƶ����壬�Ĵ��ټ�������\n"NOR,environment(ob),ob);
         write ("��һ���Ϻȣ��Ƶ����壬�Ĵ��ټ�������\n");
         got_pot=(obj_exp/my_exp)*100+random((int)ob->query_skill("lamaism",1));
         ob->add("combat_exp",got_pot*2+random(40));
                 log_file("/job/xs-duren", ctime(time()) + ob->query("name") +"(" + ob->query("id") + ")��ѩɽ����" + got_pot*2 + "�����\n" ); 
         ob->add("potential",got_pot);
		 if (ob->query("potential")>ob->query("max_potential")) ob->set("potential",ob->query("max_potential"));
         ob->add("neili",-got_pot*2+80-random(160)); 
         ob->start_busy(5);
         if ((int)ob->query("neili",1)<0)
                         {
                                ob->set("neili",0);
                                ob->unconcious();  
             }
         say("���»���ʲ��ݵ�����ʦ���ޱ߷𷨶ɻ����ˣ�ʹ����ȥ��ħ���˹���������\n");
        destruct(obj);
         call_out("destroying", 20+random(20) , obj);
                                return 1;
                 }

void destroying(object obj)
{
		this_player()->delete("assigned_asker");
        return;
}
