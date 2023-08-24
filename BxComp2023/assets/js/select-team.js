const characters = document.querySelectorAll('.character');
const characterImage = document.querySelector('.character-image img');
const characterName = document.getElementById('character-name');

characters.forEach(character => {
    character.addEventListener('click', () => {
        characters.forEach(c => c.classList.remove('selected'));
        character.classList.add('selected');

        const imgSrc = character.getAttribute('data-img');
        const name = character.getAttribute('data-name');

        characterImage.setAttribute('src', imgSrc);
        characterName.textContent = name;
    });
});
a