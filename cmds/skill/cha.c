// Code of ShenZhou
// skills.c
// Modified by xQin 04/01 to disable the possibility for players to use this cmd to check whether
// an invisible wiz is online.

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
        BLU "��ѧէ��" NOR,
        HIB "��ͨƤë" NOR,
        HIB "��������" NOR,
        HIB "��������" NOR,
        HIB "�������" NOR,
        CYN "�������" NOR,
        CYN "����似" NOR,
        CYN "�����뻯" NOR,
        HIC "�Ƿ��켫" NOR,
        HIC "һ����ʦ" NOR,
        HIW "��ɲ�" NOR
});

string *knowledge_level_desc = ({
        BLU "��ѧէ��" NOR,
        HIB "�����ž�" NOR,
        HIB "��֪һ��" NOR,
        HIB "��������" NOR,
        HIB "����С��" NOR,
        CYN "�������" NOR,
        CYN "��Ȼ���" NOR,
        CYN "��Ȼ��ͨ" NOR,
        HIC "������˫" NOR,
        HIC "������" NOR,
        HIW "��ɲ�" NOR
});

string skill_level(string, int);

int main(object me, string arg)
{
        object ob;
        mapping skl, lrn, map;
        string *sname, *mapped;
        int i;

        seteuid(getuid());

        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
//        if ( ob->query("SPSKILLS",1)  ) return ob->skills();           
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
        }

        if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
        && !me->is_apprentice_of(ob) && !ob->is_spouse_of(me))
                return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");

        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write( (ob==me ? "��" : ob->name()) + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
                return 1;
        }
        write( "[44;1m[1;33m"+(ob==me ? "��" : ob->name()) +"[44;1m[1;33mĿǰ��ѧ���ļ��ܣ�����"+chinese_number(sizeof(skl))+"��ܣ�                               [37;0m\n\n");
        sname  = sort_array( keys(skl), (: strcmp :) );
        
        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        
        for(i=0; i<sizeof(skl); i++) {
                printf("%s%s%-40s" NOR " - %-10s %3d/%5d\n", 
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (member_array(sname[i], mapped)==-1? "  ": "��"),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
        }
        write("\n");
        return 1;
}

string skill_level(string type, int level)
{
        int grade;

        grade = level / 40;

        switch(type) {
                case "knowledge":
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}

int help(object me)
{
        write(@HELP
ָ���ʽ : skills|cha [<ĳ��>]

���ָ���������(��)��ѯ��ѧ���ļ��ܡ�

��Ҳ����ָ��һ��������ʦͽ��ϵ�Ķ����� skills ���Բ�֪�Է��ļ���״����

��ʦ���Բ�ѯ�κ��˻� NPC �ļ���״����

HELP
    );
    return 1;
}