#include <map>
#include <SFML/Graphics.hpp>


struct ResourceManager
{
	// Type helper
	using StrCstRef = const std::string&;

private:
	std::string prefix;
	std::map<std::string, sf::Font> fonts;
	std::map<std::string, sf::Texture> textures;

public:
	ResourceManager(StrCstRef resource_path_prefix)
		: prefix(resource_path_prefix)
	{}

	bool registerFont(StrCstRef filename, StrCstRef alias) {
		sf::Font font;
		if (font.loadFromFile(prefix + filename)) {
			fonts[alias] = font;
			return true;
		}
		return false;
	}

	sf::Text createText(StrCstRef font, uint32_t size, sf::Color color = sf::Color::White, StrCstRef str = "")
	{
		sf::Text text;
		auto it = fonts.find(font);
		if (it != fonts.end()) {
			text.setFont(it->second);
			text.setCharacterSize(size);
			text.setFillColor(color);
			text.setString(str);
		}
		return text;
	}
};
