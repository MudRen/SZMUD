// Code of ShenZhou
//kungfu/class/emei/nun.h for ���ң�����
// Date: shan 96/11/20
// xQin 8/00

#include <ansi.h>
string ask_for_huansu()
{
        object me;
        object ob;
	ob = this_object();
        me = this_player();

        if( (string)me->query("class") != "bonze" )
                return "�����ӷ�ʩ���γ����ԣ��ҿ�ʩ�����ǳ����˰ɣ�\n";

        if( (string)me->query("gender") != "Ů��" )
        return "�����ӷ𣡴�ʦ���������������ң�\n";

        if (me->query("family/family_name") != "������" )
        {
        return "�����ӷ�"+RANK_D->query_respect(me)+"���������ˣ����������ƶ�ᡣ";
	}
	if (me->query("family/master_id") == ob->query("id"))
	{
	add_action("do_jueding", "�������");
	me->set_temp("pending/quit_bonze", 1);
	command("sigh "+me->query("id"));
	me->set("quit/bonze", 1);
	return "�����ӷ𣡼�Ȼ�㳾Եδ�ˣ�ΪʦҲ��ǿ���㣬��������ʦͽԵ��Ҳ������\n"
	       "����������ڸ����Ұɣ�(type �������)\n";
	}
	else {
	command("hmm");
	return "�����ӷ�"+RANK_D->query_respect(me)+"���Ǻ���ʦ��˵ȥ�ɡ�";
	}
}

int do_jueding()
{
	object ob, me;
	me=this_player();
	ob=this_object();
	
	if (!me->query_temp("pending/quit_bonze"))
	return 0;
	
	message_vision("$N����������������������˵��������ˡͽ����Ф����\n\n",me);
	message_vision("$N��$n̾�˿���������$N�������ָ���$Nһ�����¡�\n\n",ob,me);
	command("say �����ӷ�ʩ�����ء�");
	ob=new("clone/misc/cloth.c");
	ob->move(me);
	command("expell "+me->query("id"));
	me->delete("class", "bonze");
	me->delete_temp("pending/quit_bonze");
	return 1;
}
      
string ask_for_join()
{
        object me;
        mapping fam;

        me = this_player();

	if (me->query("quit/bonze"))
	{
		return "�����ӷ�ʩ�����Ի�����Ϊ������ƶ�����֮�£�";
	}
        if( (string)me->query("class")=="bonze" 
            || (string)me->query("class")=="bonze" )
                return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ�ƶ�Ὺ�����Ц��\n";

        if( (string)me->query("gender") != "Ů��" )
        return "�����ӷ����գ����գ�ʩ������������ҷ𣬺β�ȥ��ɽ���������С�\n";

	if( mapp(fam = me->query("family")) && (fam["family_name"] != "������")
	&& (me->query("combat_exp") > 10000)) 
		return "�����ӷ�ʩ���������ָ��֣����ֲ���������ʩ���β����Щ���Ǯ�أ�\n";

	if( mapp(fam = me->query("family")) && (fam["family_name"] != "������")
	&& (me->query("combat_exp") <= 10000)) 
		command("say �ڱ��ֳ������У�һ��Ҫ������ɣ���ɲ�Ҫ��ڡ�\n");

        if( (string)me->query("spouse/id") ) 
        	command("say ʩ�����Ҫ�뿪�ɷ�ͼ�ͥ������ҷ���\n");

       	command("say �����ӷ����գ����գ�ʩ������������ҷ������(kneel)�ܽ䡣\n");
	
        me->set_temp("pending/join_bonze", 1);
		return	"��ס��һ�����˼ң��ǲ��ܻ��׵ģ����򽫻��ܵ��ͷ���\n";

}

int do_kneel()
{
        object me = this_player();

        string *prename =
         ({ "��", "��", "��", "��" });
        string name, sujia_name, nun_name;

        if( !me->query_temp("pending/join_bonze") )
                return 0;

        message_vision(
                "$N˫�ֺ�ʮ�����������ع���������\n\n"
                "$n����$N˵�����ðɣ�����ڱ������аɡ�\n\n"
                "$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ��������ȥ��\n\n",
                me, this_object() );
        name = me->query("name");
        nun_name = prename[random(sizeof(prename))] + name[0..1];
        command("say �ӽ��Ժ���ķ����ͽ���" + nun_name + "��");
        command("chat " + name + "����Ϊ�ᣬ�ڶ���ɽ���У�ȡ����" + nun_name + "��");
        command("smile");
	me->set("title", "������ѧ��Ů");
        me->delete_temp("pending/join_bonze");
	me->set("sujia_name", name);
        me->set("name", nun_name);
        me->set("class", "bonze");
        me->delete("family");
	MARRY_D->break_marriage(me);
        me->set("K_record", me->query("PKS") + me->query("MKS"));

        return 1;
}

