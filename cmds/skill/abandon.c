//Ҷ���޸��� 13/10/2001
// abandon.c


#include <ansi.h>
inherit F_CLEAN_UP;
mapping valid_types = ([
	"unarmed":      "ȭ��",
	"sword":        "����",
	"blade":        "����",
	"stick":        "����",
	"staff":        "�ȷ�",
	"club" :        "����",
	"force":        "�ڹ�",
	"parry":        "�м�",
	"dodge":        "�Ṧ",
	"magic":        "����",
	"whip":         "�޷�",
	"hammer":       "����",
	"kick":         "�ȷ�",
	"hook":         "����",
	"pike":         "ǹ��",
	"finger":       "ָ��",
	"hand":         "�ַ�",
	"cuff":         "ȭ��",
	"claw":         "צ��",
	"strike":       "�Ʒ�",
]);
int main(object me, string arg)
{
	mapping skills, skillmap, pmap;
	string *skill, skillname, name;
	object ob;
	int i, level;

	if( !arg || arg=="" ) 
		return notify_fail("��Ҫ������һ��ܣ�\n");

        level = me->query_skill(arg, 1);
        
/*	if( !me->delete_skill(arg) )
		return notify_fail("�㲢û��ѧ������ܡ�\n");
*/
	if( arg =="all" ) {
		skills = me->query_skills();
		if( !mapp(skills) || sizeof(skills)==0 )
	                return notify_fail("�㲢û��ѧϰ�κεļ��ܡ�\n");

		if( me != this_player(1) ) return 0;
	
		ob = me->query_temp("link_ob");
		if( !ob ) return 0;
		while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

		write(HIR"���Ƿ������������ѧϰ���еļ��ܣ��������������Ҳ�����ٰ���ָ���\n"NOR"����������������ѧϰ���еļ��ܣ����������"HIG"�������룺"NOR);
                input_to("delete_all", ob);
	} else {		 
		name = arg;
		skillname = to_chinese(name);
//	      	if( !mapp(skillmap) || sizeof(skillmap)==0 ) return 1;              
		if (!me->query_skill(name))
  {
     write("ok��\n");
     me->delete_skill(name);
     return 1;
  }
		if( me != this_player(1) ) return 0;
	
		ob = me->query_temp("link_ob");
		if( !ob ) return 0;
		while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");
		write(HIR"�������������ѧϰ" + HIG +skillname+ HIR + "���������������Ҳ�����ٰ���ָ���\n"NOR"����������������ѧϰ" + HIG +skillname+ NOR + "�����������"HIG"�������룺"NOR); 
                input_to("delete_skill", ob, arg, skillname, name);
	}
	return 1;
}

private void delete_all(string pass, object ob, string *skill)
{
	mapping skills, pmap, skillmap;
	int i;
	object me = this_player();
	string old_pass;

	write("\n");
	old_pass = ob->query("check_password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write("��������㲻�ܷ��������书��\n");
		return;
	}
	skills = me->query_skills();
        pmap = me->query_skill_prepare();
	skillmap = me->query_skill_map();
	write(HIC"�������������ѧϰ���еļ��ܡ�\n"NOR);
	skill = keys(valid_types);
	if ( !(!mapp(skillmap) || sizeof(skillmap)==0 )){
		for (i=0; i<sizeof(skill); i++) 
		{
                        if( undefinedp(valid_types[skill[i]]))
			{
				map_delete(skillmap, skill[i]);
	                        map_delete(pmap, skill[i]);
				continue;
			}
			if( !me->query_skill(skill[i]) ) continue;
			if(skillmap[skill[i]])
			{
				write("ȥ��������"+to_chinese(skill[i])+" => "+to_chinese(skillmap[skill[i]])+"��\n");
				me->map_skill(skill[i]);
			}
		}
	}
	skill = keys(skills);
	for (i=0; i<sizeof(skill); i++) {
		me->delete_skill(skill[i]);
	}
}

private void delete_skill(string pass, object ob, string *skill, string skillname, string name)
{
	mapping skillmap, pmap, skills;
	int i;
	object me = this_player();
	string old_pass,*skill2;

	write("\n");
	old_pass = ob->query("check_password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write("��������㲻�ܷ���" + HIG +skillname+ NOR + "��\n");
		return;
	}
	skills = me->query_skills();
        pmap = me->query_skill_prepare();
	skillmap = me->query_skill_map();
	if( !(!mapp(skillmap) || sizeof(skillmap)==0 ))
	{
		skill = keys(valid_types);
		for (i=0; i<sizeof(skill); i++) 
		{
                        if( undefinedp(valid_types[skill[i]])) 
			{
				map_delete(skillmap, skill[i]);
	                        map_delete(pmap, skill[i]);
				continue;
			}
			if( !me->query_skill(skill[i]) ) continue;
			if(skillmap[skill[i]]==name)
			{
				write("ȥ��������"+to_chinese(skill[i])+" => "+to_chinese(skillmap[skill[i]])+"��\n");
				me->map_skill(skill[i]);
			}
		}
	}
	if(!me->delete_skill(name)) return;
	write(HIC"�������������ѧϰ" + HIG +skillname+ HIC + "��\n"NOR);
	skill = keys(skills);
	for (i=0; i<sizeof(skill); i++) {
		if( skills[skill[i]] == name ) me->map_skill(skill[i]);
		}
}
int help()
{
	write(@TEXT
ָ���ʽ��abandon|fangqi <��������>

����һ������ѧ���ļ��ܣ�ע��������˵�ġ���������ָ������ܴ�������
��������ɾ����������Ժ�Ҫ��������ӣ���ʼ����������ؿ��������

���ָ��ʹ�õĳ���ͨ��������ɾ��һЩ����С�ġ��������ļ��ܣ�����ÿ��
�����Ų�ͬ���츳������ϰ���书Ҳ������ͬ�����������ѧ����ͷ��ֻ����
��������
TEXT
	);
	return 1;
}
