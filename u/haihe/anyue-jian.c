// ����֮�����κ�ר��  anyue-jian.c
// by naihe  2002-04-26
// by naihe  2002-04-29 �������������Լ��鿴�ʵصĺ�����2002-05-12 �������ɱ�˼�����
// 05-16 ���������жϷ�ʽ�����ڵİ��½���˵��3.1��ɣ�

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void delete_obj();

int tempa,tempb,temp,
tempa = (random(200)),
tempb = (random(200));

void create()
{
        set_name(BLU"����֮��"NOR, ({ "anyue jian", "jian", "sword" }));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�˽���֪����ô�ʵ����(flip)�����ž�Ȼ��ƮƮ�ظо����������������Ͽ�\n�ż�����С���֣���"BLU"����֮�� �������� ��Ѫ�޺� ������Ȼ --��ɽ�ɡ��κ�"NOR"��\n");
                set("value", 0);
                set("no_steal", "����Ҳ��͵������Ц�ա�\n");
                set("rigidity", 200);
                set("shape", ({ "long", "sword" }) );
//              set("material", "steel"); // ��Ҫ������ʵء���
                set("wield_msg", ""MAG"$N�������"NOR"$n��"MAG"��ʱ��һ�������������"NOR"\n"HIB"���ʱ�е�һ����ɭɱ����\n"NOR"" );
                set("unwield_msg", ""MAG"$N��������������е�"NOR"$n"MAG"����˽��ʡ�\n"NOR""HIB"һ�����ε�ѹ����Ȼ��ʧ���㲻�ɵ����˿�����"NOR"\n");
	}
        if (tempa>tempb) temp=tempb;
        else temp=tempa;
        init_sword(1+temp);
        setup();
}

void init()
{
        add_action("do_wield", "wield");
        add_action("do_flip", "flip");
        add_action("do_aya", "aya");
        add_action("do_ayb", "ayb");
}

int do_wield(string arg)
{
        object me = this_player();

	if(arg=="anyue jian" || arg=="jian" || arg=="sword" || arg=="all")
	{
	        if(me->query("id") =="naihe" || me->query("id") =="spark" || wizardp(me))
		{
	                set("wield_msg", ""MAG"$N�������"NOR"$n��"MAG"��ʱ��һ�������������"NOR"\n"HIB"���ʱ�е�һ����ɭɱ����\n"NOR"" );
        	        set("unwield_msg", ""MAG"$N��������������е�"NOR"$n"MAG"����˽��ʡ�\n"NOR""HIB"һ�����ε�ѹ����Ȼ��ʧ���㲻�ɵ����˿�����"NOR"\n");	
		        if (tempa>tempb) temp=tempb;
			        else temp=tempa;
	                set("rigidity", 200);
			init_sword(1+temp);
			return 0;
		}

		else
        	{
                	set("wield_msg", "$N���������$n�������С�\n" );
	                set("unwield_msg", "$N�����е�$n����˽��ʡ�\n");
		        init_sword(1);
			temp=1;
	                delete("rigidity");
			call_out("delete_obj",3+random(5));
                	return 0;
	        }
	}
        return 0;
}

int do_flip(string arg)
{
        object me = this_player();

	if(!present("anyue jian",me)) return notify_fail("�������ε�����ȥ�������������̫���Źۣ���\n");

        if(!arg)
        {
                if(me->query("jing") < me->query("max_jing")/2)
                return notify_fail("�㱻"BLU"����֮��"NOR"�������ƣ���Ȼ�޷���ָ���£�\n");

                message_vision("$N�����ָ��"BLU"����֮��"NOR"��һ����ֻ���á�������һ�����죬���Ӳ�����\n",me);
                if(me->query("id") == "naihe") write("������Ϊ"+temp+"��\n");

                if(temp<15) write("�⽣���������������֪�Ȳ��ȵ���Ѱ��������\n");
                if(temp>14 && temp<40) write("��ѽ��������ã��ƺ�Ҫ��ƽ��������ʤһ�\n");
                if(temp>39 && temp<80) write("��ѽ���â���䣬һ����֪����������\n");
                if(temp>79 && temp<100) write("��ֻ������һ�£���Ȼ����һ����ɲ�Ǽ䴫����ȫ����ʵ���ǰ��ѵõı�����\n");
                if(temp>99 && temp<150) write("�˽��������ˣ��������ƺ�������������ƣ������˼䣬��˱���ʵ���Ǽ��亱�У�\n");
                if(temp>149) write("�˽�֮Ϭ�����ѿ������졢����һ�ϸ��£�\n");
                if(temp >= 200) write("�˽�֮��������ֱ�ѵ���������֮��֮���ޣ�\n");

                message_vision("$N��"BLU"����֮��"NOR"������Ϯ����Щ������������\n",me);
                me->set("jing",1);
                return 1;
        }
        return 0;
}

void delete_obj()
{
        message_vision(""HIB"\nһ�����ĵ�̾Ϣ��֪�Ӻδ�������ֻ��"NOR""BLU"����֮��"NOR""HIB"����Ĺ�â�漴�������ˣ�����������ʧ������"NOR"\n",this_object());
        destruct(this_object());
}

// ����֮��֮�ռ�ɱ�˼���
int do_aya(string arg)
{
        object me,ob;
        string whoa,whob;
	
        me=this_player();

// �������޽�����ͨ����
	if(!present("anyue jian",me)) return notify_fail("���ڵ����ء�\n");

// ����ʱ���ڵȴ���ʧ����ͨ����
        if(this_object()->query("delete_obj") == 1) return 1;

// ��û�й���Ŀ�꣬��ͨ����
        if(!arg) return notify_fail("��ʽ��aya <id>\n");

// ���˽�δװ������ͨ����
	if(!this_object()->query("equipped") )
		return notify_fail(""BLU"����֮��"NOR"��δ���ʣ�\n");

// ���˵��޴��ˣ���ͨ����
        ob=present(arg,environment(me));
        if(!ob) return notify_fail("����û��������\n");     

// ������δ��ս��״̬����ͨ��������ս��״̬�Ļ������Թ����κ��ˣ�
	if(!me->is_fighting()) return notify_fail("��δ��Ѫ������ͨ�飡\n");

// ��ָ�����Ǳ���ID����ͨ����
	if("arg"==me->query("id")) return notify_fail("��������֮��������������ɱ֮�\n");

// ���빥���κλ���˸����ͨ����
        if(arg=="naihe" || arg=="spark") return notify_fail(""BLU"����֮��"NOR"�������ˣ�����������������\n");

// �����˷���ʦ���κλ���˸����ͨ����
	if(me->query("id")!="naihe" && me->query("id")!="spark" && !wizardp(me))
		return notify_fail("�������������֮������ȴ��Ϊ������\n");

// �ж���ϣ���ʼɱ���ˣ�����
        whoa=(string)me->query("name");
        whob=(string)ob->query("name");

        tell_room(environment(me),""HIB"ֻ����"+whoa+"��ȻһЦ���е���������֮�����ѵ��㻹�������𣿣���"NOR"\n"HIR"ֻ��"NOR""BLU"����֮��"NOR""HIR"��"+whoa+"���м������������"+whob+"�����࣡"NOR"\n",({me,ob}));
        tell_object(ob,""HIR"ֻ����"+whoa+"һ����Ц������ǰ��ৡ��ػ���һĨ��Ӱ��"NOR""BLU"����֮��"NOR""HIR"��Ȼ����������ţ�"NOR"\n");
        write(""HIB"���ȻһЦ���е���������֮�����ѵ��㻹�������𣿣���"NOR"\n"HIR"ֻ������֮���������м������������"+whob+"�����࣡"NOR"\n");
        ob -> set_temp("last_damage_from", "��"+whoa+"ɱ����");
        ob -> die();

        set("delete_obj",1);
        call_out("delete_obj",3);
        me->start_busy(random(10));
        return 1;
}

void atk_backing()
{
        message_vision(""HIR"\nֻ��"NOR""BLU"����֮��"NOR""HIR"ת�˸�Ȧ���ַɻ���$N�����С�"NOR"\n",this_player());
	this_object()->delete("attack_backing");
}

// ����֮��֮Ͷ��ɱ�˼���
int do_ayb(string arg)
{
        object me,ob;
        string whoa,whob,can_do_it;
        int neili,melose,oblose,qi;

	me=this_player();
        neili=me->query("max_neili");

	if(!present("anyue jian",me)) return notify_fail("���ڵ����ء�\n");
        if(!arg) return notify_fail("��ʽ��aya <id>\n");
        if(this_object()->query("attack_backing") == 1) return notify_fail("����û�ɻ����ء�\n");
	if(!this_object()->query("equipped") )
		return notify_fail(""BLU"����֮��"NOR"��δ���ʣ�\n");
        ob=present(arg,environment(me));
        if(!ob) return notify_fail("����û��������\n");     
	if(!me->is_fighting()) return notify_fail("��δ��Ѫ������ͨ�飡\n");
	if("arg"==me->query("id")) return notify_fail("��������֮��������������ɱ֮�\n");
        if(arg=="naihe" || arg=="spark") return notify_fail(""BLU"����֮��"NOR"�������ˣ�����������������\n");
	if(me->query("id")!="naihe" && me->query("id")!="spark" && !wizardp(me))
		return notify_fail("�������������֮������ȴ��Ϊ������\n");
        if(neili<100) return notify_fail("��û���㹻����������������֮������\n");
        if((int)me->query("neili")<(neili*2/3)) return notify_fail("���Ѿ�û���㹻����������������֮������\n");

        whoa=(string)me->query("name");
        whob=(string)ob->query("name"); 
        qi=ob->query("max_qi");

        tell_room(environment(me),""HIB"ֻ����"+whoa+"�����е���������֮������Ѫ�޺ۣ���"NOR"\n"HIR"ֻ��"NOR""BLU"����֮��"NOR""HIR"��"+whoa+"���м��������ֱ��"+whob+"��ȥ��\n"+whob+"���������ȴ�Ա��������ˣ�"NOR"\n",({me,ob}));
        tell_object(ob,""HIB"ֻ����"+whoa+"�����е���������֮������Ѫ�޺ۣ�����һĨ��Ӱ���㼤�������\n"NOR""HIR"���鼱֮���������ӣ���Ȼ�����ܹ�����������Ȼ����������ش���"NOR"\n");
        write(""HIB"�������е���������֮������Ѫ�޺ۣ���"NOR"\n"HIR"ֻ��"NOR""BLU"����֮��"NOR""HIR"�������м��������ֱ��"+whob+"��ȥ��\n"+whob+"���������ȴ�Ա��������ˣ�"NOR"\n");

        melose=(neili/2+(random(neili/2)));
        if(melose>(int)me->query("neili")) melose=me->query("neili");
        oblose=(qi/4+(random(qi/2)));

        if(me->query("id")=="naihe") write("�õ�"+melose+"�����������"+oblose+"���˺���\n");

        me->start_busy(5); // æʱ5�룡ʡ�ó��֡����ɳ�ȥ�ˡ����һ��������Ž����˵����������
        me->add("neili",-melose);
        ob->add("qi",-oblose);

        set("attack_backing",1);
        call_out("atk_backing",3);	

        return 1; 
}
