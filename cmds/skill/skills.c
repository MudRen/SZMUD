//Cracked by Roath
// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;
string bar_string = "                                   ";
string tribar_graph(int a);
string *skill_level_desc = ({
        BLU "│ї╤з╒з┴╖" NOR,
        HIB "┤╓═и╞д├л" NOR,
        HIB "░ы╔·▓╗╩ь" NOR,
        HIB "┬э┬э╗в╗в" NOR,
        HIB "╝▌╟с╛═╩ь" NOR,
        CYN "│Ў└р░╬▌═" NOR,
        CYN "╔ё║ї╞ф╝╝" NOR,
        CYN "│Ў╔ё╚ы╗п" NOR,
        HIC "╡╟╖х╘ь╝л" NOR,
        HIC "╥╗┤·╫┌╩ж" NOR,
        HIW "╔ю▓╗┐╔▓т" NOR
});

string *knowledge_level_desc = ({
        BLU "╨┬╤з╒з╙├" NOR,
        HIB "│ї┐·├┼╛╢" NOR,
        HIB "┬╘╓к╥╗╢■" NOR,
        HIB "┬э┬э╗в╗в" NOR,
        HIB "╥╤╙╨╨б│╔" NOR,
        CYN "╨─┴ь╔ё╗с" NOR,
        CYN "┴╦╚╗ь╢╨╪" NOR,
        CYN "╗э╚╗╣с═и" NOR,
        HIC "╛┘╩└╬▐╦л" NOR,
        HIC "╒Ё╣┼юх╜ё" NOR,
        HIW "╔ю▓╗┐╔▓т" NOR
});

string skill_level(string, int);

int main(object me, string arg)
{
        object ob;
        mapping skl, lrn, map;
        string *sname, *mapped, name;
        int i,j;

        seteuid(getuid());

        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
//        if ( ob->query("SPSKILLS",1)  ) return ob->skills();           
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("─у╥к▓ь┐┤╦н╡─╝╝─▄г┐\n");
        }

        if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
        && !me->is_apprentice_of(ob) && !ob->is_spouse_of(me))
                return notify_fail("─у╥к▓ь┐┤╦н╡─╝╝─▄г┐\n");

        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write( (ob==me ? "─у" : ob->name()) + "─┐╟░▓в├╗╙╨╤з╗с╚╬║╬╝╝─▄бг\n");
                return 1;
        }
	if(ob==me)name="─у";
	else name=ob->name();
	write( "[44;1m[1;33m"+name+"[44;1m[1;33m─┐╟░╦∙╤з╣¤╡─╝╝─▄г║ги╣▓"+chinese_number(sizeof(skl))+"╧ю╝╝─▄гй"+tribar_graph(strlen(name)+strlen(chinese_number(sizeof(skl))))+"[37;0m\n\n");
        sname  = sort_array( keys(skl), (: strcmp :) );
        
        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        j=0;

        for(i=0; i<sizeof(skl); i++) {
                if(SKILL_D(sname[i])->type()=="knowledge"){
                j=j+1;
                }
        }
        if(j>0) { printf("[32mй░[42m%21s    [40m[32mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй┤[37;0m\n", "[37m"+chinese_number(j)+"╧ю╓к╩╢");}
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type()=="knowledge"){
                printf("[32mйж[37;0m%s%s%-34s" NOR " - %-10s %4d/%9d[32mйж[37;0m\n", 
                        (member_array(sname[i], mapped)==-1? "  ": "[1;32mбї[37;0m"),
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
        if(j>0) { write("[32mй╕йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй╝[37;0m\n");}

	j=0;
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() == "base_skill"){
        	j=j+1;
                }
        }
        if(j>0) { printf("[32mй░[42m%21s    [40m[32mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй┤[37;0m\n", "[37m"+chinese_number(j)+"╧ю╗∙▒╛╣ж╖Є");}
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() == "base_skill"){
                printf("[32mйж[37;0m%s%s%-34s" NOR " - %-10s %4d/%9d[32mйж[37;0m\n", 
                        (member_array(sname[i], mapped)==-1? "  ": "[1;32mбї[37;0m"),
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
        if(j>0) { write("[32mй╕йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй╝[37;0m\n");}

	j=0;
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && SKILL_D(sname[i])->type() != "knowledge2" && SKILL_D(sname[i])->type() != "base_skill"){
        	j=j+1;
                }
        }
        if(j>0) { printf("[32mй░[42m%21s    [40m[32mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй┤[37;0m\n", "[37m"+chinese_number(j)+"╧ю╠╪╩т╣ж╖Є");}
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && SKILL_D(sname[i])->type() != "knowledge2" && SKILL_D(sname[i])->type() != "base_skill"){
                printf("[32mйж[37;0m%s%s%-34s" NOR " - %-10s %4d/%9d[32mйж[37;0m\n", 
                        (member_array(sname[i], mapped)==-1? "  ": "[1;32mбї[37;0m"),
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
        if(j>0) { write("[32mй╕йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй╝[37;0m\n");}

        j=0;

        for(i=0; i<sizeof(skl); i++) {
                if(SKILL_D(sname[i])->type()=="knowledge2"){
                j=j+1;
                }
        }
        if(j>0) { printf("[32mй░[42m%21s    [40m[32mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй┤[37;0m\n", "[37m"+chinese_number(j)+"╧ю╓░╥╡╝╝─▄");}
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type()=="knowledge2"){
                printf("[32mйж[37;0m%s%s%-34s" NOR " - %-10s %4d/%9d[32mйж[37;0m\n", 
                        (member_array(sname[i], mapped)==-1? "  ": "[1;32mбї[37;0m"),
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
        if(j>0) { write("[32mй╕йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй╝[37;0m\n");}

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
                case "knowledge2":
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}
string tribar_graph(int a)
{
	return bar_string[0..(35 - a)];
}
int help(object me)
{
        write(@HELP
╓╕┴ю╕ё╩╜ : skills|cha [<─│╚╦>]

╒т╕Ў╓╕┴ю┐╔╥╘╚├─у(─у)▓щ╤п╦∙╤з╣¤╡─╝╝─▄бг

─у╥▓┐╔╥╘╓╕╢и╥╗╕Ў║═─у╙╨╩ж═╜╣╪╧╡╡─╢╘╧єгм╙├ skills ┐╔╥╘▓щ╓к╢╘╖╜╡─╝╝─▄╫┤┐Ўбг

╬╫╩ж┐╔╥╘▓щ╤п╚╬║╬╚╦╗Є NPC ╡─╝╝─▄╫┤┐Ўбг

HELP
    );
    return 1;
}
